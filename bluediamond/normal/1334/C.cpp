#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 300000 + 7;
const ll INF = (ll) 1e18;
int n;
ll a[N];
ll b[N];
ll c[N];

int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);

        /// freopen ("input", "r", stdin);

        int t;
        cin >> t;
        while (t--) {
                cin >> n;
                for (int i = 0; i < n; i++) {
                        cin >> a[i] >> b[i];
                }
                ll sumc = 0;
                for (int i = 0; i < n; i++) {
                        int j = (i + 1) % n;
                        c[j] = max(0LL, a[j] - b[i]);
                        sumc += c[j];
                }
                ll ans = INF;
                for (int i = 0; i < n; i++) {
                        ans = min(ans, sumc - c[i] + a[i]);
                }
                cout << ans << "\n";
        }

}