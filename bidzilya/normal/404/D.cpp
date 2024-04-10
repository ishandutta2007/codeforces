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

const int modulo = 1e9 + 7;

const int max_n = 1e6 + 100;

char a[max_n];
int dp[max_n][4][3];
int n;

bool check(int pos, char c) {
    if (a[pos] == '?') return true;
    return a[pos] == c;
}

void minc(int& a, int x) {
    a += x;
    if (a >= modulo) a -= modulo;
}

int main() {
   // freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
    
    while (scanf("%s\n", a) != EOF) {
        n = strlen(a);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < 4; ++j)
                for (int k = 0; k < 3; ++k)
                    dp[i][j][k] = 0;
        if (a[0] == '?') {
            dp[0][0][0] = 1;
            dp[0][1][1] = 1;
            dp[0][2][2] = 1;
            dp[0][3][0] = 1;
        } else if (a[0] == '*') {
            dp[0][3][0] = 1;
        } else if (a[0] == '2') {
            dp[0][2][2] = 1;
        } else if (a[0] == '1') {
            dp[0][1][1] = 1;
        } else if (a[0] == '0') {
            dp[0][0][0] = 1;
        }
        for (int i = 0; i + 1 < n; ++i) {
            if (check(i + 1, '1')) minc(dp[i + 1][1][1], dp[i][1][0]);
            if (check(i + 1, '0')) minc(dp[i + 1][0][0], dp[i][1][0]);
            
            if (check(i + 1, '*')) minc(dp[i + 1][3][0], dp[i][1][1]);
            
            if (check(i + 1, '1')) minc(dp[i + 1][1][1], dp[i][0][0]);
            if (check(i + 1, '0')) minc(dp[i + 1][0][0], dp[i][0][0]);
            
            if (check(i + 1, '*')) minc(dp[i + 1][3][0], dp[i][3][0]);
            if (check(i + 1, '1')) minc(dp[i + 1][1][0], dp[i][3][0]);
            if (check(i + 1, '2')) minc(dp[i + 1][2][1], dp[i][3][0]);
            
            if (check(i + 1, '*')) minc(dp[i + 1][3][0], dp[i][2][1]);
        }
        int ans = 0;
        for (int j = 0; j < 4; ++j) {
            minc(ans, dp[n - 1][j][0]);
        }
        printf("%d\n", ans);
    }

    return 0;
}