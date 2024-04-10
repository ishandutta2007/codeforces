#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 16;
const int MAXM = 300;
const int INF = 1000000007;

bool X[MAXN];
int R[MAXN], B[MAXN];
int f[1 << MAXN][2][MAXM];

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    int RR = 0, BB = 0;
    for (int i = 0; i < N; ++i) {
        char c;
        int a, b;
        cin >> c >> a >> b;
        if (c == 'R') X[i] = false; else X[i] = true;
        if (a > N) {
            RR += a - N;
            a = N;
        }
        if (b > N) {
            BB += b - N;
            b = N;
        }
        R[i] = a;
        B[i] = b;
    }
    for (int i = 0; i < (1 << N); ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k <= N * N; ++k) {
                f[i][j][k] = INF;
            }
        }
    }
    // Maybe not 0, check who is left, RR or BB
    if (RR > BB) {
        f[0][1][min(RR - BB, N * N)] = 0;
    } else {
        f[0][0][min(BB - RR, N * N)] = 0;
    }
    for (int i = 0; i < (1 << N) - 1; ++i) {
        int RRR = 0, BBB = 0;
        for (int l = 0; l < N; ++l) {
            if (i & (1 << l)) {
                if (X[l]) ++BBB; else ++RRR;
            }
        }

        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k <= N * N; ++k) {
                if (f[i][j][k] == INF) continue;
            //    cout << i << " " << j << " " << k << " " << f[i][j][k] <<  " -> to " << endl; 
                for (int l = 0; l < N; ++l) {
                    if (i & (1 << l)) continue;
                    int a = 0, b = 0;
                    if (j == 0) a = k; else b = k;
                    int T = max(max(R[l] - RRR, 0) - a, max(B[l] - BBB, 0) - b);
                    a = a + T - max(R[l] - RRR, 0);
                    b = b + T - max(B[l] - BBB, 0);
                  //  if (a != 0 && b != 0) cout << "ERROR" << endl;
                    if (a > N * N) a = N * N;
                    if (b > N * N) b = N * N;
                    if (a == 0) {
                        f[i + (1 << l)][1][b] = min(f[i + (1 << l)][1][b], f[i][j][k] + T + 1);
                     //   cout << i + (1 << l) << " " << 1 << " " << b << " " << f[i + (1 << l)][1][b] << endl;
                    } else {
                        f[i + (1 << l)][0][a] = min(f[i + (1 << l)][0][a], f[i][j][k] + T + 1);
                      //  cout << i + (1 << l) << " " << 0 << " " << a << " " << f[i + (1 << l)][0][a] << endl;
                    }
                }
            }
        }
    }

    int ans = INF;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j <= N * N; ++j) ans = min(ans, f[(1 << N) - 1][i][j]);
    }
    cout << ans + max(RR, BB) << endl;

    return 0;
}