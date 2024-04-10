#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
const int N = 2000 + 7;
const int OO = (int) 1e9;
int n;
int h;
ld p_left;
ld p_right;
int x[N];
ld e[N][N][2][2];
bool connected[N];
int tor[N];
int tol[N];

int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);

        cin >> n >> h >> p_left;
        p_right = 1.0 - p_left;
        for (int i = 1; i <= n; i++) {
                cin >> x[i];
        }
        sort(x + 1, x + n + 1);
        for (int i = 1; i < n; i++) {
                if (x[i] + h > x[i + 1]) {
                        connected[i] = 1;
                }
        }
        for (int i = 1; i <= n; i++) {
                if (connected[i - 1]) {
                        tol[i] = tol[i - 1];
                } else {
                        tol[i] = i;
                }
        }
        for (int i = n; i >= 1; i--) {
                if (connected[i]) {
                        tor[i] = tor[i + 1];
                } else {
                        tor[i] = i;
                }
        }
        x[0] = -OO;
        x[n + 1] = +OO;
        for (int len = 1; len <= n; len++) {
                for (int l = 1; l + len - 1 <= n; l++) {
                        int r = l + len - 1;
                        for (int d1 = 0; d1 <= 1; d1++) {
                                for (int d2 = 0; d2 <= 1; d2++) {
                                        ld sol = 0;


                                        /// first left
                                                /// falls right
                                                if (tor[l] >= r) {
                                                        sol += p_right * (x[r] - x[l]);
                                                        sol += p_right * min(h, x[r + 1] - h * (d2 == 0) - x[r]);
                                                } else {
                                                        int p = tor[l];
                                                        sol += p_right * e[p + 1][r][1][d2];
                                                        sol += p_right * (x[p] - x[l] + h);
                                                }
                                                /// falls left
                                                sol += p_left * e[l + 1][r][0][d2];
                                                sol += p_left * min(h, x[l] - (x[l - 1] + h * (d1 == 1)));
                                        /// first right
                                                /// falls left
                                                if (tol[r] <= l) {
                                                        sol += p_left * (x[r] - x[l]);
                                                        sol += p_left * min(h, x[l] - (x[l - 1] + h * (d1 == 1)));
                                                } else {
                                                        int p = tol[r];
                                                        sol += p_left * e[l][p - 1][d1][0];
                                                        sol += p_left * (x[r] - x[p] + h);
                                                }
                                                /// falls right
                                                sol += p_right * e[l][r - 1][d1][1];
                                                sol += p_right * min(h, x[r + 1] - h * (d2 == 0) - x[r]);
                                        e[l][r][d1][d2] = 0.5 * sol;
                                }
                        }
                }
        }
        cout << fixed << setprecision(6) << e[1][n][0][1] << "\n";
}