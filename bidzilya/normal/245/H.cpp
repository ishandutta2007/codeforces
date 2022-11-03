#include <cstdio>
#include <cstring>

#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>
using namespace std;

#ifndef ONLINE_JUDGE
ifstream cin("input.txt");
ofstream cout("output.txt");
#else
#include <iostream>
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;

const int max_n = 5e3 + 100;

char s[max_n];
int n;
int dp[max_n][max_n];
bool is_pal[max_n][max_n];

int main() {
    scanf("%s", s);
    n = strlen(s);
    for (int len = 1; len <= n; ++len)
        for (int i = 0; i + len <= n; ++i) {
            int j = i + len - 1;
            if (s[i] == s[j] && (i + 1 > j - 1 || is_pal[i + 1][j - 1]))
                is_pal[i][j] = 1;
            else
                is_pal[i][j] = 0;
        }
    for (int len = 1; len <= n; ++len)
        for (int i = 0; i + len <= n; ++i) {
            int j = i + len - 1;
            if (j - 1 >= i) {
                dp[i][j] += dp[i][j - 1];
                dp[i][j] += dp[i + 1][j];
                dp[i][j] -= dp[i + 1][j - 1];
            }
            if (is_pal[i][j])
                ++dp[i][j];
        }
    int q;
    for (scanf("%d", &q); q; --q) {
        int l, r;
        scanf("%d%d", &l, &r);
        --l; --r;
        printf("%d\n", dp[l][r]);
    }
    return 0;
}