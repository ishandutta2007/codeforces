#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

int cost(int a, int b) {
        if (b == 1)
                return (int) 1e9 + 7;
        int ret = 0;
        while (a) {
                ret++;
                a /= b;
        }
        return ret;
}

signed main() {
        ios::sync_with_stdio(0); cin.tie(0);

        int t;
        cin >> t;
        while (t--) {
                int a, b, ret = (int) 1e9 + 7;
                cin >> a >> b;
                for (int add = 0; add < 40; add++) {
                        ret = min(ret, add + cost(a, b + add));
                }
                cout << ret << "\n";
        }
}