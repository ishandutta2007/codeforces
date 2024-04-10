#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);

        int t;
        cin >> t;
        while (t--) {
                int n;
                cin >> n;
                int h = n / 2;
                if (h % 2 == 1) {
                        cout << "NO\n";
                } else {
                        cout << "YES\n";
                        ll s = 0;
                        for (int i = 1; i <= h; i++) {
                                cout << 2 * i << " ";
                                s += 2 * i;
                        }
                        for (int i = 1; i < h; i++) {
                                cout << 2 * i - 1 << " ";
                                s -= (2 * i - 1);
                        }
                        cout << s << "\n";
                }
        }

}