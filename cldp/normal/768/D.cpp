#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1000000007;
const int MAXM = 8010;
const int MAXN = 1010;
const double EPS = 1e-7;

double f[MAXM][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int K, Q;
    cin >> K >> Q;
    f[0][0] = 1;
    for (int i = 1; i < MAXM; ++i) {
        for (int j = 1; j <= K; ++j) {
            f[i][j] = f[i - 1][j] * j / K + f[i - 1][j - 1] * (K - j + 1) / K;
        }
    }
    
    for (int i = 0; i < Q; ++i) {
        int P;
        cin >> P;
        if (K == 1) {
            cout << 1 << endl;
            continue;
        }
        for (int j = K; j < MAXM; ++j) {
            if (f[j][K] >= 1.0 * (P - EPS) / 2000) {
                cout << j << endl;
                break;
            }
        }
    }
    
    return 0;
}