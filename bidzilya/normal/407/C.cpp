#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

const int max_n = 1e5 + 10;
const int modulo = 1e9 + 7;
const int max_k = 111;

inline void minc(int& x, int d) { x += d; if (x >= modulo) x -= modulo; }
inline void mdec(int& x, int d) { x -= d; if (x < 0) x += modulo; }

int a[max_n][max_k];
int n, m;
int C[max_n + max_k][max_k];

int main() {
    for (int i = 0; i < max_n + max_k; ++i)
        C[i][0] = 1;
    for (int j = 1; j < max_k; ++j)
        C[0][j] = 0;
    for (int i = 1; i < max_n + max_k; ++i)
        for (int j = 1; j < max_k; ++j) {
            C[i][j] = C[i - 1][j];
            minc(C[i][j], C[i - 1][j - 1]);
        }
        
  //  freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);

    while (scanf("%d%d", &n, &m) != EOF) {
        for (int i = 0; i < n; ++i)
            scanf("%d", &a[i][0]);
        for (int i = 0; i < n; ++i)
            for (int k = 1; k < max_k; ++k)
                a[i][k] = 0;
        for (int i = 0; i < m; ++i) {
            int l, r, k;
            scanf("%d%d%d", &l, &r, &k);
            --l; --r;
            minc(a[l][k + 1], 1);
            for (int j = 1; j <= k + 1; ++j)
                mdec(a[r + 1][j], C[r - l + k + 1 - j][k + 1 - j]);
        }
        for (int k = max_k - 2; k >= 0; --k) {
            int sum = 0;
            for (int i = 0; i < n; ++i) {
                minc(sum, a[i][k + 1]);
                minc(a[i][k], sum);
            }
        }
        for (int i = 0; i < n; ++i)
            printf("%d ", a[i][0]);
        printf("\n");
    }
    

    return 0;
}