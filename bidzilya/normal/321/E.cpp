#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <map>
#include <cassert>
using namespace std;

const int kInf = 1e9;

int n, k;
vector<vector<int> > u;
vector<vector<int> > cost;
vector<vector<int> > dp;

void Calc(int tk, int ln, int rn, int lon, int ron)
{
    int mn = (ln + rn) >> 1;
    int best_con = max(lon, mn);
    for (int con = max(lon, mn); con <= ron; ++con) {
        int cur_val = cost[mn][con] + dp[con + 1][tk - 1];

        if (cur_val < dp[mn][tk]) {
            dp[mn][tk] = cur_val;
            best_con = con;
        }
    }
    if (ln != rn) {
        Calc(tk, ln, mn, lon, best_con);
        Calc(tk, mn + 1, rn, best_con, ron);
    }
}

const int kTempSize = 8e3 + 1;

char temp[kTempSize];

int main()
{
    scanf("%d%d\n", &n, &k);

    u.resize(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        gets(temp);
        for (int j = 0; j < n; ++j) {
            u[i][j] = temp[2 * j] - '0';
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            u[i][j] += u[i][j - 1];
        }
    }

    cost.resize(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        cost[i][i] = 0;
        for (int j = i + 1; j < n; ++j) {
            cost[i][j] = cost[i][j - 1] + u[j][j - 1];
            if (i > 0) {
                cost[i][j] -= u[j][i - 1];
            }
        }
    }

    dp.assign(n + 1, vector<int>(k + 1, kInf));
    dp[n][0] = 0;
    for (int tk = 1; tk <= k; ++tk) {
        Calc(tk, 0, n - 1, 0, n - 1);
    }

    printf("%d\n", dp[0][k]);

    return 0;
}