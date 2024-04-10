#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll N=12;

set<ll>s[N+1];
ll v[N+1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    s[0].insert(0);
    for(ll i=1;i<=N;i++) {
        for(auto x:s[i-1]) {
            s[i].insert(x+1);
            s[i].insert(x+5);
            s[i].insert(x+10);
            s[i].insert(x+50);
        }
        v[i]=s[i].size();
    }
    ll x,ans=0;cin>>x;
    if(x<=N)ans=v[x];
    else
        ans=v[N]+49*(x-N);
    cout<<ans<<"\n";
    return 0;
}
/**

**/