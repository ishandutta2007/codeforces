#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 11111111, inf = 1000000007;

long long dp[max_n][5];
string s;

void update(int poz, int x, int value) {
    dp[poz][x] = (dp[poz][x] + value) % inf;
}

void update(int poz, int x) {
    if (x <= 1) {
        if (s[poz + 1] == '0' || s[poz + 1] == '?') {
            update(poz + 1, 0, dp[poz][x]);
        }
        if (s[poz + 1] == '1' || s[poz + 1] == '?') {
            update(poz + 1, 2, dp[poz][x]);
        }
    }
    if (x == 2 || x == 3) {
        if (s[poz + 1] == '*' || s[poz + 1] == '?') {
            update(poz + 1, 4, dp[poz][x]);
        }
    }
    if (x == 4) {
        if (s[poz + 1] == '1' || s[poz + 1] == '?') {
            update(poz + 1, 1, dp[poz][x]);
        }
        if (s[poz + 1] == '2' || s[poz + 1] == '?') {
            update(poz + 1, 2, dp[poz][x]);
        }
        if (s[poz + 1] == '*' || s[poz + 1] == '?') {
            update(poz + 1, 4, dp[poz][x]);
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s;
    if (s[0] == '0' || s[0] == '?') {
        dp[0][0] = 1;
    }
    if (s[0] == '1' || s[0] == '?') {
        dp[0][2] = 1;
    }
    if (s[0] == '*' || s[0] == '?') {
        dp[0][4] = 1;
    }
    int i;
    for (i = 0; i + 1 < s.length(); ++i) {
        //cout << i << "  -  ";
        for (int j = 0; j < 5; ++j) {
            update(i, j);
            //cout << dp[i][j] << ' ';
        }
        //cout << endl;
    }
    long long ans = 0;
    if (s[i] == '?') {
        ans = dp[i][0] + dp[i][1] + dp[i][3] + dp[i][4];
    }
    if (s[i] == '*') {
        ans = dp[i][4];
    }
    if (s[i] == '0') {
        ans = dp[i][0];
    }
    if (s[i] == '2') {
        ans = dp[i][3];
    }
    if (s[i] == '1') {
        ans = dp[i][1];
    }
    cout << (ans % inf + inf) % inf << endl;
    return 0;
}