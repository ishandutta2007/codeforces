#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=998244353;

ll qpow(ll a,ll n){
    ll res=1;
    while(n){
        if(n&1){
            res=res*a%mod;
        }
        a=a*a%mod;
        n>>=1;
    }
    return res;
}

void add(pair<ll,ll> &a,pair<ll,ll> b){
    a.first=a.first*b.second+a.second*b.first;
    a.second=a.second*b.second;
    a.first%=mod;
    a.second%=mod;
}

int n;
vector<int> a[1000005];
map<int,int> mp;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        int k,kk;
        cin>>k;
        while(k--){
            cin>>kk;
            a[i].push_back(kk);
            mp[kk]++;
        }
    }
    pair<ll,ll> ans=make_pair(0,1);
    for(int i=1;i<=n;i++){
        pair<ll,ll> p=make_pair(0,1);
        for(int j=0;j<a[i].size();j++){
            add(p,make_pair(mp[a[i][j]],(ll)n*n%mod*a[i].size()%mod));
        }
        add(ans,p);
    }
    cout<<ans.first*qpow(ans.second,mod-2)%mod;

    return 0;
}