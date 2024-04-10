#include <bits/stdc++.h>
#ifdef JLOCAL
#include "stress.h"
#endif
using namespace std;

#define rep(i, z, n) for (int i = (z); i < int(n); ++i)
#define repr(i, n, z) for (int i = int(n) - 1; i >= (z); --i)
#define shl(n) (1 << (n))
#define hbit(n, i) (((n) >> (i)) & 1)

#define STRESS 0
using lint = long long;
template <typename T> using vc = std::vector<T>;

void solve(istream& cin, ostream& cout) {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }

    while (true) {
        int x = -1, y = -1;
        rep(i, 0, n) {
            rep(j, 0, m) {
                if (a[i][j] == '#') {
                    x = i;
                    y = j;
                }
            }
        }

        if (x == -1) {
            break;
        }

        vector<int> rs(n), cs(m);
        rep(i, 0, n) {
            if (a[i][y] == '#') {
                rs[i] = 1;
            }
        }
        rep(i, 0, m) {
            if (a[x][i] == '#') {
                cs[i] = 1;
            }
        }

        rep(i, 0, n) {
            if (rs[i]) {
                rep(j, 0, m) {
                    if (cs[j] == 0 && a[i][j] == '#' || cs[j] == 1 && a[i][j] == '.') {
                        cout << "No";
                        return;
                    }
                }
            }
        }

        rep(j, 0, m) {
            if (cs[j]) {
                rep(i, 0, n) {
                    if (rs[i] == 0 && a[i][j] == '#' || rs[i] == 1 && a[i][j] == '.') {
                        cout << "No";
                        return;
                    }
                }
            }
        }

        rep(i, 0, n) {
            rep(j, 0, m) {
                if (rs[i] && cs[j]) {
                    assert(a[i][j] == '#');
                    a[i][j] = '.';
                }
            }
        }
    }

    cout << "Yes";
}

int main() {
#if !defined(JLOCAL) || !STRESS
#ifdef JLOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve(cin, cout);
#else
    srand();
    for (int ti = 0; ti < 100; ti++) {
        stress::gen();
        stress::stupid();
        ifstream in("input.txt");
        ofstream out("output.txt");
        solve(in, out);
        out.flush();
        stress::check();
    }
    cout << "ok" << endl;
#endif
    return 0;
}