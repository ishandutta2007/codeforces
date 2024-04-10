#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

int z[256];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    z['a'] = 0;
    z['b'] = 1;
    ll n, k;
    cin >> n >> k;
    string s, t;
    cin >> s >> t;
    ll ans = 0;
    ll lo = 0, hi = 0;
    ll diff = 0;
    for(int i=0;i<n;++i) {
        lo = lo*2 + z[s[i]];
        hi = hi*2 + z[t[i]];
        lo = (lo&((1LL<<40)-1));
        hi = (hi&((1LL<<40)-1));
        diff = max(hi-lo, diff);
        ans += min(diff+1, k);
    }
    cout << ans << endl;
    return 0;
}