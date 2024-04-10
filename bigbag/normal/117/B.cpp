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

const int max_n = 11111111, inf = 1000000000;

int a, b, mod, dp[max_n];

void write(int x) {
    int k = x, len = 0;
    while (k) {
        k /= 10;
        ++len;
    }
    for (int i = 0; i < 9 - len; ++i) {
        cout << 0;
    }
    cout << x << endl;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> a >> b >> mod;
    for (int i = 0; i < mod; ++i) {
        dp[i] = inf;
    }
    int o = inf % mod;
    int x = 0;
    for (int i = 0; i < mod + 11; ++i) {
        dp[x] = min(dp[x], i);
        x += o;
        if (x >= mod) {
            x -= mod;
        }
    }
    int mn = inf;
    for (int i = 1; i < mod; ++i) {
        if (dp[i] != inf && dp[i] <= a) {
            mn = i;
            break;
        }
    }
    if (mn == inf) {
        cout << 2 << endl;
        return 0;
    }
    x = mod - mn;
    if (x <= b) {
        cout << 2 << endl;
        return 0;
    }
    cout << 1 << " ";
    int ans = inf;
    for (int i = 1; i < mod; ++i) {
        if (dp[i] != inf && dp[i] <= a) {
            mn = i;
            x = mod - mn;
            if (x > b) {
                ans = min(ans, dp[i]);
            }
        }
    }
    write(ans);
    return 0;
}