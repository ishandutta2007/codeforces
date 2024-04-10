#include <bits/stdc++.h>
using namespace std;
#define int long long
#define maxn 100090
#define PII pair<int, int>

int t, n, x[maxn];

int32_t main() {
    cin.tie(0), cout.sync_with_stdio(0);
    cin >> t;
    while (t -- ) {
        cin >> n;
        for (int i = 1; i <= n; ++ i) cin >> x[i];

        int v1 = 0, v2 = 0;

        for (int i = 1; i <= n; ++ i) v1 += x[i], v2 ^= x[i];

        int goal1 = (1ll << 60), goal2 = (1ll << 59);

        int sum = goal1 - v1, a2 = 0, a3 = 0, a1 = goal2 ^ v2;
        
        a2 = a3 = (sum - a1) / 2;

//        for (int i = 60; i >= 1; -- i) {
//            if ((a1 & (1ll << i)) && ((wnt & (1ll << i) == 0))) {
//                a1 ^= (1ll << i);
//                a2 ^= (1ll << (i - 1));
//                a3 ^= (1ll << (i - 1));
//            }
//        }
        assert((v1 + a1 + a2 + a3) == 2 * (v2 ^ a1 ^ a2 ^ a3));
        cout << 3 << "\n" << a1 << " " << a2 << " " << a3 << endl;
    }
    return 0;
}