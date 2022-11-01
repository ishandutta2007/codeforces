#include<bits/stdc++.h>
using namespace std;

const int mod=1e9+7;

int qpow(long long a,int n){
    long long res=1;
    while(n){
        if(n&1)res=res*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return res;
}

int n,a[100005],mx;

int solve(int m){
    vector<pair<int,int>> v;
    for(int i=1;i*i<=m;i++){
        if(m%i==0){
            v.emplace_back(i,0);
            if(i*i!=m)v.emplace_back(m/i,0);
        }
    }
    sort(v.begin(),v.end());
    for(pair<int,int> &p:v){
        p.second=lower_bound(a+1,a+1+n,p.first)-a;
    }
    for(int i=0;i+1<v.size();i++){
        v[i].second=v[i+1].second-v[i].second;
    }
    v.back().second=n+1-v.back().second;
    long long res=1;
    for(int i=0;i+1<v.size();i++){
        res=res*qpow(i+1,v[i].second)%mod;
    }
    return (qpow(v.size(),v.back().second)-qpow(v.size()-1,v.back().second)+mod)%mod*res%mod;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    sort(a+1,a+1+n);
    int ans=0;
    for(int i=1;i<=mx;i++){
        ans=(ans+solve(i))%mod;
    }
    cout<<ans<<endl;

    return 0;
}