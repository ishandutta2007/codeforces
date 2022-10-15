#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int ll


signed main() {
        ios::sync_with_stdio(0); cin.tie(0);

        ///freopen ("input", "r", stdin);

        int t;
        cin >> t;
        while (t--) {
                int xmin, xmax, ymin, ymax;
                xmin = 0;
                xmax = 0;
                ymin = 0;
                ymax = 0;
                int x, y;
                string s;
                cin >> x >> y >> s;
                for (auto &ch : s) {
                        if (ch == 'R') xmax++;
                        if (ch == 'L') xmin--;
                        if (ch == 'U') ymax++;
                        if (ch == 'D') ymin--;
                }
                if (xmin <= x && x <= xmax && ymin <= y && y <= ymax)
                        cout << "YES\n";
                else
                        cout << "NO\n";
        }

}
/**

**/