#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 77777 + 7;
const int MOD = 777777777;

int add(int a, int b) {
        a += b;
        if (a >= MOD) {
                return a - MOD;
        }
        if (a < 0) {
                return a + MOD;
        }
        return a;
}

int mul(int a, int b) {
        return a * (ll) b % MOD;
}

int n;
int q;
bool ok[4][4];

struct T {
        bool gl;
        int sol[4][4];
        T() {
                gl = 0;
                for (int i = 0; i <= 3; i++) {
                        for (int j = 0; j <= 3; j++) {
                                sol[i][j] = 0;
                        }
                }
        }
};

T t[4 * N];
T gol;

bool operator == (T a, T b) {
        for (int i = 0; i <= 3; i++) {
                for (int j = 0; j <= 3; j++) {
                        if (a.sol[i][j] != b.sol[i][j]) {
                                return 0;
                        }
                }
        }
        return 1;
}

T operator + (T x, T y) {
        if (x.gl) {
                return y;
        }
        if (y.gl) {
                return x;
        }
        T z;
        for (int b = 1; b <= 3; b++) {
                for (int c = 1; c <= 3; c++) {
                        if (ok[b][c]) {
                                for (int a = 1; a <= 3; a++) {
                                        for (int d = 1; d <= 3; d++) {
                                                z.sol[a][d] = add(z.sol[a][d], mul(x.sol[a][b], y.sol[c][d]));
                                        }
                                }
                        }
                }
        }
        return z;
}

void upd(int v, int tl, int tr, int p, int x) {
        if (tr < p || p < tl) {
                return;
        }
        if (tl == tr) {
                if (x == 0) {
                        for (int i = 1; i <= 3; i++) {
                                t[v].sol[i][i] = 1;
                        }
                } else {
                        for (int i = 1; i <= 3; i++) {
                                t[v].sol[i][i] = 0;
                        }
                        t[v].sol[x][x] = 1;
                }
                return;
        }
        int tm = (tl + tr) / 2;
        upd(2 * v, tl, tm, p, x);
        upd(2 * v + 1, tm + 1, tr, p, x);
        t[v] = t[2 * v] + t[2 * v + 1];
}

T get(int v, int tl, int tr, int l, int r) {
        if (tr < l || r < tl) {
                return gol;
        }
        if (l <= tl && tr <= r) {
                return t[v];
        }
        int tm = (tl + tr) / 2;
        return get(2 * v, tl, tm, l, r) + get(2 * v + 1, tm + 1, tr, l, r);
}

void make(int i, int x) {
        upd(1, 1, n, i, x);
}

int get() {
        T it = get(1, 1, n, 1, n);
        ll sol = 0;
        for (int i = 1; i <= 3; i++) {
                for (int j = 1; j <= 3; j++) {
                        sol = add(sol, it.sol[i][j]);
                }
        }
        return sol;
}

int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);

        gol.gl = 1;
        cin >> n >> q;
        for (int i = 1; i <= 3; i++) {
                for (int j = 1; j <= 3; j++) {
                        cin >> ok[i][j];
                }
        }
        for (int i = 1; i <= n; i++) {
                make(i, 0);
        }
        while (q--) {
                int i, x;
                cin >> i >> x;
                make(i, x);
                cout << get() << "\n";
        }

}