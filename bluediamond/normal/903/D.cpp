#include <bits/stdc++.h>

using namespace std;

typedef long double ll;

const int N=200000;
ll n,v[N+5];
map<ll,ll>mp;
ll ans=0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>v[i];
        ans-=mp[v[i]-1];
        ans+=mp[v[i]+1];
        mp[v[i]]++;
    }
    ll scad=0;
    for(int i=1;i<=n;i++) {
        scad+=v[i];
        ans+=(ll)i*(ll)v[i];
        ans-=(ll)scad;
    }
    cout<<fixed<<setprecision(0)<<ans<<"\n";
    return 0;
}
/**



**/