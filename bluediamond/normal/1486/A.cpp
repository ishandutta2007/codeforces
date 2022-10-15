#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

const int N = 100 + 7;
int n, a[N];

signed main() {
        ios::sync_with_stdio(0); cin.tie(0);

       /// freopen ("input", "r", stdin);

        int t;
        cin >> t;
        while (t--) {
                cin >> n;
                for (int i = 1; i <= n; i++) {
                        cin >> a[i];
                }
                bool ok = 1;
                for (int i = 1; i < n; i++) {
                        int pot = a[i] - a[i - 1] - 1;
                        if (i == 1)
                                pot = a[i];
                        a[i] -= pot;
                        a[i + 1] += pot;
                        if (a[i] >= a[i + 1]) {
                                cout << "NO\n";
                                ok = 0;
                                break;
                        }

                }
                if (ok)
                        cout << "YES\n";

        }

}