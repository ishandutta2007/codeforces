#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

signed main() {
        ios::sync_with_stdio(0); cin.tie(0);

        int t;
        cin >> t;
        while (t--) {
                int n, mn = (int) 1e9, cnt = 0;
                cin >> n;
                for (int i = 1; i <= n; i++) {
                        int x;
                        cin >> x;
                        if (x < mn) {
                                mn = x;
                                cnt = 1;
                        } else
                                cnt += (mn == x);
                }
                cout << n - cnt << "\n";
        }
}