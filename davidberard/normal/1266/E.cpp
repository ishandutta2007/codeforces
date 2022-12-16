#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int N = 200200;

map<pii, int> mp;
ll in[N];
ll a[N];
ll ans = 0;

int n, q;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; ++i) {
        cin >> a[i];
        ans += a[i];
    }
    cin >> q;
    while (q--) {
        int u, v, w;
        cin >> u >> v >> w;
        if (mp.count(pii(u, v))) {
            int x = mp[pii(u, v)];
            ans -= max(0ll, a[x]-in[x]);
            --in[x];
            mp.erase(pii(u, v));
            ans += max(0ll, a[x]-in[x]);
        }

        if (w) {
            ans -= max(0ll, a[w]-in[w]);
            mp[pii(u, v)] = w;
            ++in[w];
            ans += max(0ll, a[w]-in[w]);
        }

        cout << ans << "\n";
    }
    return 0;
}