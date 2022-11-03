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

const int max_k = 50;
const int max_n = 1e3 + 10;
const int max_a = 1e3 + 10;
const int modulo = 1e9 + 7;

int dp[max_k][max_a][max_n];
int fact[max_k];

void minc(int& dst, int src) {
    dst += src;
    if (dst >= modulo) dst -= modulo;
}

int C[max_n + max_k][max_k];

map<pair<int, int>, int> anss;

int main() {
  //  freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
    
    dp[0][0][0] = 1;
    for (int cnt = 0; cnt < max_k; ++cnt)
        for (int last = 0; last < max_a; ++last)
            for (int pos = 0; pos < max_n; ++pos) {
                if (last + 1 < max_a)
                    minc(dp[cnt][last + 1][pos], dp[cnt][last][pos]);
                if (cnt + 1 < max_k && last + 1 < max_a && pos + last + 1 < max_n) 
                    minc(dp[cnt + 1][last + 1][pos + last + 1], dp[cnt][last][pos]);
            }

    fact[0] = 1;
    for (int i = 1; i < max_k; ++i) 
        fact[i] = (1LL * fact[i - 1] * i) % modulo;
        
    for (int i = 0; i < max_n + max_k; ++i)
        C[i][0] = 1;
    for (int j = 1; j < max_k; ++j)
        C[0][j] = 0;
    for (int i = 1; i < max_n + max_k; ++i)
        for (int j = 1; j < max_k; ++j) {
            C[i][j] = C[i - 1][j];
            minc(C[i][j], C[i - 1][j - 1]);
        }
    
    anss.clear();
    
    int tests;
    for (scanf("%d", &tests); tests; --tests) {
        int n, k;
        scanf("%d%d", &n, &k);
        if (k >= max_k) {
            printf("0\n");
        } else {
            pair<int, int> temp(n, k);
            if (anss.find(temp) != anss.end()) {
                printf("%d\n", anss[temp]);
                continue;
            }
            int res = 0;
            for (int m = n; m >= 0; --m) {
                int cres = (1LL * C[k + n - m][k] * dp[k][max_a - 1][m]) % modulo;
                minc(res, cres);
            }
            res = (1LL * res * fact[k]) % modulo;
            printf("%d\n", res);
            anss[temp] = res;
        }
    }
    return 0;
}