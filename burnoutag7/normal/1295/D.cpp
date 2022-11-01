#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a,ll b){
    while(b!=0){
        a=a%b;
        swap(a,b);
    }
    return a;
}

ll calc(vector<ll> &v,ll m,ll g){
    int n=v.size();
    ll res=0;
    for(int s=0;s<1<<n;s++){
        ll cur=g;
        for(int i=0;i<n;i++){
            if(s>>i&1){
                cur*=v[i];
            }
        }
        if(__builtin_popcount(s)&1){
            res-=m/cur;
        }else{
            res+=m/cur;
        }
        //cerr<<res<<endl;
    }
    return res;
}

ll solve(ll a,ll m,ll g){
    ll cur=m/g;
    vector<ll> v;
    for(ll i=2;i*i<=cur;i++){
        if(cur%i==0){//cerr<<cur<<endl;
            while(cur%i==0)cur/=i;
            v.push_back(i);
        }
    }
    if(cur>1)v.push_back(cur);
    return calc(v,a,g);
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    ll a,m;
    cin>>T;
    while(T--){
        cin>>a>>m;//cerr<<"GCD"<<gcd(a,m)<<endl;
        cout<<solve(a+m-1,m,gcd(a,m))-solve(a-1,m,gcd(a,m))<<endl;
    }

    return 0;
}