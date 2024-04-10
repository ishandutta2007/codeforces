#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

struct Edge {
        int x, y, c;
};

vector<Edge> ret;

int Log(int x) {
        if (x == 1)
                return 0;
        else
                return 1 + Log(x / 2);
}

signed main() {
        ios::sync_with_stdio(0); cin.tie(0);
        cout << "YES\n";

        int l, r, add;
        cin >> l >> r;
        if (l == r) {
                cout << "2 1\n";
                cout << "1 2 " << l << "\n";
                return 0;
        }
        add = (l - 1);
        l = 1;
        r -= add;

        int k = Log(r - 1), y = 0;
        /// vreau sa fac [1...2^y] pt fiecare 0<=y<=k si asta se gaseste in nodul y + 2

        ret.push_back({1, 2, 1});
        y = 2;
        /// am facut 2^0
        int alr = 1;
        for (int p = 1; p <= k; p++) {
                /// am bulan ca 2^0 + ... + 2^(p - 1) = 2^p - 1
                y++;
                ret.push_back({1, y, 1});
                alr = 1;
                for (int p2 = 0; p2 < p; p2++) {
                        ret.push_back({p2 + 2, p + 2, alr});
                        alr += (1 << p2);
                }
                assert(alr == (1 << p));
        }
        /// acum in k+3 formez numarul yeye
        assert(y == k + 2);
        y++;
        alr = 1;
        ret.push_back({1, y, 1});
        for (int p = 0; p <= k; p++) {
                if ((r - 1) & (1 << p)) {
                        ret.push_back({p + 2, y, alr});
                        alr += (1 << p);
                }
        }
        assert(alr == r);
        if (add) {
                y++;
                ret.push_back({y - 1, y, add});
        }
        cout << y << " " << (int) ret.size() << "\n";
        for (auto &it : ret)
                cout << it.x << " " << it.y << " " << it.c << "\n";

}