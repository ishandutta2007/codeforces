#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m,a[100005];
ll ans;

inline void calc(const ll& k){
    map<ll,int> mp;
    static ll f;
    f=0;
    for(int i=1;i<=n;i++)mp[f+=a[i]]++;
    f=0;
    for(int i=1;i<=n;i++){
        ans+=mp[f+k];
        mp[f+=a[i]]--;
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        calc(1);
    }else if(m==-1){
        calc(1);
        calc(-1);
    }else for(ll k=1;abs(k)<=(ll)1e14;k*=m)calc(k);
    cout<<ans<<'\n';

    return 0;
}