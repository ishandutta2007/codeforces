#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int ll


signed main() {
        ios::sync_with_stdio(0); cin.tie(0);

      ///  freopen ("input", "r", stdin);

        int t;
        cin >> t;
        while (t--) {
                int n, k;
                cin >> n >> k;
                vector<int> h(n);
                for (int i = 0; i < n; i++)
                        cin >> h[i];
                int id = 0;
                while (k > 0 && id != -1) {
                        id = -1;
                        for (int i = 0; i + 1 < n; i++) {
                                if (h[i] >= h[i + 1])
                                        continue;
                                int times = min(k, h[i + 1] - h[i]);
                                times = 1;
                                h[i] += times;
                                id = i + 1;
                                k -= times;
                                break;
                        }
                }
                assert(id != 0);
                cout << id << "\n";
        }

}
/**

**/