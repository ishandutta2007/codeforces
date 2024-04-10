#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
const int INF = 1000000007;
const double PI = acos(-1.0);

int f[MAXN][1 << 12];
bool x[4][MAXN];

void update(int &A, int B) {
    if (A == -1) A = B; else A = min(A, B);
}

int main() {
    ios_base::sync_with_stdio(false);
    int N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    for (int i = 0; i < 4; ++i) {
        string Q;
        cin >> Q;
        for (int j = 0; j < N; ++j) x[i][j] = (Q[j] == '*');
    }

    N += 3;
    memset(f, -1, sizeof(f));
    int temp = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (x[j][i]) temp |= (1 << (i * 4 + j));
        }
    }
    f[2][temp] = 0;
    for (int i = 2; i < N; ++i) {
        for (int j = 0; j < (1 << 12); ++j) {
            if (f[i][j] == -1) continue;
            temp = 0;
            for (int k = 0; k < 4; ++k) {
                if (x[k][i + 1]) temp |= (1 << k);
            }
            temp <<= 8;
            update(f[i + 1][0], f[i][j] + D);
            update(f[i + 1][temp], f[i][j] + C + C);
            update(f[i + 1][((j & 2048) >> 4) + temp], f[i][j] + B + C);
            update(f[i + 1][((j & 2176) >> 4) + temp], f[i][j] + __builtin_popcount(j & 8) * A + C);
            update(f[i + 1][((j & 256) >> 4) + temp], f[i][j] + B + C);
            update(f[i + 1][((j & 272) >> 4) + temp], f[i][j] + __builtin_popcount(j & 1) * A + C);
            update(f[i + 1][((j & 3840) >> 4) + temp], f[i][j] + B + B);
            update(f[i + 1][((j & 4032) >> 4) + temp], f[i][j] + B + __builtin_popcount(j & 12) * A);
            update(f[i + 1][((j & 3984) >> 4) + temp], f[i][j] + B + __builtin_popcount(j & 9) * A);
            update(f[i + 1][((j & 3888) >> 4) + temp], f[i][j] + B + __builtin_popcount(j & 3) * A);
            update(f[i + 1][(j >> 4) + temp], f[i][j] + __builtin_popcount(j & 15) * A);
        }
    }
    cout << f[N][0] << endl;

    return 0;
}