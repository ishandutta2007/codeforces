#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

int func(int x, int y) {
        int ret = 0;
        while (x * 2 < y) {
                ret++;
                x *= 2;
        }
        return ret;
}

signed main() {
        ios::sync_with_stdio(0); cin.tie(0);

        int t;
        cin >> t;
        while (t--) {
                int n, ant, ret = 0;
                cin >> n >> ant;
                for (int i = 2; i <= n; i++) {
                        int x;
                        cin >> x;
                        ret += func(min(ant, x), max(ant, x));
                        ant = x;
                }
                cout << ret << "\n";
        }

}