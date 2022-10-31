#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1000005;

mt19937_64 rng(chrono::steady_clock().now().time_since_epoch().count());
int n, lp[N]; ll hsh[N];
map<ll, int> mp;

void out(vector<int> v){
    for(auto x : v) lp[x] = -1;
    cout << n-v.size() << '\n';
    for(int i = 1; i<=n; ++i)
        if(lp[i]>=0) cout << i << ' ';
    cout << '\n'; exit(0);
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i = 2; i<=n; ++i){
        if(lp[i]) continue; lp[i] = i;
        for(int j = i; j<=n; j+=i)
            if(!lp[j]) lp[j] = i;
    }
    for(int i = 2; i<=n; ++i)
        if(lp[i]==i) hsh[i] = rng();
    for(int i = 2; i<=n; ++i)
        hsh[i] = hsh[i/lp[i]]^hsh[lp[i]];
    for(int i = 2; i<=n; ++i)
        hsh[i] ^= hsh[i-1];
    ll tot = 0;
    for(int i = 1; i<=n; ++i)
        tot ^= hsh[i];
    if(tot==0) out({});
    for(int i = 1; i<=n; ++i)
        if(tot==hsh[i]) out({i});
    for(int i = 1; i<=n; ++i)
        mp[hsh[i]] = i;
    for(int i = 1; i<=n; ++i)
        if(mp.count(tot^hsh[i]))
            out({i, mp[tot^hsh[i]]});
    tot ^= hsh[n];
    for(int i = 1; i<=n; ++i)
        if(mp.count(tot^hsh[i]))
            out({i, mp[tot^hsh[i]], n});
}