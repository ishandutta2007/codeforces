#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = (int) 1e5 + 7;
int n;
int k;
int a[N];

int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);

       // freopen ("input", "r", stdin);
        int t;
        cin >> t;
        while (t--) {
                cin >> n >> k;
                for (int i = 1; i <= n; i++) {
                        cin >> a[i];
                }
                sort(a + 1, a + n + 1);
                reverse(a + 1, a + n + 1);
                int ans = 0;
                ll s = 0;
                for (int i = 1; i <= n; i++) {
                        s += a[i];
                        if (s >= k * (ll) i) {
                                ans = i;
                        }
                }
                cout << ans << "\n";
        }

}