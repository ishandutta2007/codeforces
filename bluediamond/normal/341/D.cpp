#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 500 + 7;

struct Copacel {
private :
        ll menta[N][N];
public :
        Copacel() {
                for (int i = 0; i < N; i++) {
                        for (int j = 0; j < N; j++) {
                                menta[i][j] = 0;
                        }
                }
        }
        ll get(int r, int c) {
                ll zbu = 0;
                for (int i = r; i >= 1; i -= i & (-i)) {
                        for (int j = c; j >= 1; j -= j & (-j)) {
                                zbu ^= menta[i][j];
                        }
                }
                return zbu;
        }
        void upd(int r, int c, ll x) {
                for (int i = r; i < N; i += i & (-i)) {
                        for (int j = c; j < N; j += j & (-j)) {
                                menta[i][j] ^= x;
                        }
                }
        }
};

Copacel co[2][2];

ll prefix(int r, int c) {
        return co[r % 2][c % 2].get((r + 1) / 2, (c + 1) / 2);
}

void add_on_sufix(int r, int c, ll val) {
        co[r % 2][c % 2].upd((r + 1) / 2, (c + 1) / 2, val);
}

int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);

        int n, cntI;
        cin >> n >> cntI;
        while (cntI--) {
                int t, r1, c1, r2, c2;
                cin >> t >> r1 >> c1 >> r2 >> c2;
                if (t == 2) {
                        ll x;
                        cin >> x;
                        add_on_sufix(r1, c1, x);
                        add_on_sufix(r1, c2 + 1, x);
                        add_on_sufix(r2 + 1, c1, x);
                        add_on_sufix(r2 + 1, c2 + 1, x);
                } else {
                        cout << (prefix(r2, c2) ^ prefix(r1 - 1, c2) ^ prefix(r2, c1 - 1) ^ prefix(r1 - 1, c1 - 1)) << "\n";
                }
        }

}