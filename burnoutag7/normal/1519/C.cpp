#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,u[200005];
vector<vector<ll>> a;

void mian(){
    cin>>n;
    a=vector<vector<ll>>(n,vector<ll>());
    for(int i=0;i<n;i++){
        cin>>u[i];
        u[i]--;
    }
    for(int i=0;i<n;i++){
        int s;
        cin>>s;
        a[u[i]].emplace_back(s);
    }
    sort(a.begin(),a.end(),[](const vector<ll> &x,const vector<ll> &y){
        return x.size()>y.size();
    });
    for(vector<ll> &x:a){
        sort(x.begin(),x.end(),greater<ll>());
        for(int i=1;i<x.size();i++)x[i]+=x[i-1];
    }
    for(int k=1;k<=n;k++){
        ll ans=0;
        for(int i=0;i<n&&a[i].size()>=k;i++)ans+=a[i][a[i].size()-a[i].size()%k-1];
        cout<<ans<<' ';
    }
    cout<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}