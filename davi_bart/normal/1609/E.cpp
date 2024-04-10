#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define fi first
#define se second
#define ld long double
#define pb push_back
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int dim = 300;
int N, Q;
string s;
int p[100010][3];
int k[500][3][3];

void solve() {
    cin >> N >> Q;
    cin >> s;

    for (int a = 0; a < N; a += dim) {
        for (int b = 0; b < 3; b++) {
            for (int i = a; i < min(N + 4, a + dim + 2); i++) {
                for (int j = 0; j < 3; j++) {
                    p[i][j] = 1e9;
                }
            }
            p[a][b] = 0;

            for (int i = a; i < min(N, a + dim); i++) {
                p[i][1] = min(p[i][1], p[i][0]);
                p[i][2] = min(p[i][2], p[i][1]);
                for (int j = 0; j < 3; j++) {
                    // prendo 'a'
                    p[i + 1][max((int)1, j)] = min(p[i + 1][max((int)1, j)], p[i][j] + (s[i] != 'a'));
                    // prendo 'b'
                    if (j >= 1) {
                        p[i + 1][2] = min(p[i + 1][2], p[i][j] + (s[i] != 'b'));
                    } else {
                        p[i + 1][j] = min(p[i + 1][j], p[i][j] + (s[i] != 'b'));
                    }

                    // prendo 'c'
                    if (j < 2) {
                        p[i + 1][j] = min(p[i + 1][j], p[i][j] + (s[i] != 'c'));
                    }
                }
            }

            k[a / dim][b][0] = p[min(N, a + dim)][0];
            k[a / dim][b][1] = p[min(N, a + dim)][1];
            k[a / dim][b][2] = p[min(N, a + dim)][2];
        }
    }

    while (Q--) {
        int a;
        char x;
        cin >> a >> x;
        a--;
        s[a] = x;

        int ff = max((int)(0), (a - 10) / dim);
        int gg = min((N + dim - 1) / dim, (a + dim + 10) / dim);

        for (int a = ff * dim; a < gg * dim; a += dim) {
            for (int b = 0; b < 3; b++) {
                for (int i = a; i < min(N + 4, a + dim + 2); i++) {
                    for (int j = 0; j < 3; j++) {
                        p[i][j] = 1e9;
                    }
                }
                p[a][b] = 0;

                for (int i = a; i < min(N, a + dim); i++) {
                    p[i][1] = min(p[i][1], p[i][0]);
                    p[i][2] = min(p[i][2], p[i][1]);
                    for (int j = 0; j < 3; j++) {
                        // prendo 'a'
                        p[i + 1][max((int)1, j)] = min(p[i + 1][max((int)1, j)], p[i][j] + (s[i] != 'a'));
                        // prendo 'b'
                        if (j >= 1) {
                            p[i + 1][2] = min(p[i + 1][2], p[i][j] + (s[i] != 'b'));
                        } else {
                            p[i + 1][j] = min(p[i + 1][j], p[i][j] + (s[i] != 'b'));
                        }

                        // prendo 'c'
                        if (j < 2) {
                            p[i + 1][j] = min(p[i + 1][j], p[i][j] + (s[i] != 'c'));
                        }
                    }
                }

                k[a / dim][b][0] = p[min(N, a + dim)][0];
                k[a / dim][b][1] = p[min(N, a + dim)][1];
                k[a / dim][b][2] = p[min(N, a + dim)][2];
            }
        }

        int q[3] = {0, 0, 0};
        int q1[3] = {1000000000, 1000000000, 1000000000};

        for (int i = 0; i < N; i += dim) {
            int x = i / dim;
            for (int a = 0; a < 3; a++) {
                for (int b = 0; b < 3; b++) {
                    // cout << k[x][a][b] << " ";
                    q1[b] = min(q1[b], q[a] + k[x][a][b]);
                }
            }
            q[0] = q1[0];
            q[1] = q1[1];
            q[2] = q1[2];

            q1[0]=q1[1]=q1[2]=1e9;
        }

        int mi = 1e9;
        for (int i = 0; i < 3; i++) {
            mi = min(mi, q[i]);
        }
        cout << mi << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}