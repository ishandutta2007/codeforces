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

const int max_n = 111, inf = 1111111111;

int n, k, f[max_n][max_n];
long long dp[max_n][max_n];
vector<int> g[max_n];
vector<string> z[max_n];
map<string, string> ant;

bool ok(int l, int r, int x, int y, int l2, int r2) {
    for (int q = 0; q < 2; ++q) {
        for (int i = 0; i < g[x].size(); ++i) {
            if (z[x][i] == "=") {
                if (g[x][i] != y && g[x][i] != x) {
                    return false;
                }
            }
            if (z[x][i] == "<") {
                if (g[x][i] < l || g[x][i] > r) {
                    return false;
                }
            }
            if (z[x][i] == ">") {
                if (g[x][i] > l2 && g[x][i] <= r2) {
                    return false;
                }
            }
            if (z[x][i] == "<=") {
                if (g[x][i] < l2 || g[x][i] > r2) {
                    return false;
                }
            }
            if (z[x][i] == ">=") {
                if (g[x][i] > l && g[x][i] < r) {
                    return false;
                }
            }
        }
        swap(x, y);
    }
    return true;
}

void get_dp(int l, int r) {
    if (f[l][r]) {
        return;
    }
    f[l][r] = 1;
    if (l + 1 == r) {
        if (ok(l + 1, r - 1, l, r, l, r)) {
            dp[l][r] = 1;
        }
        return;
    }
    if (ok(l + 1, r - 1, l, r, l, r)) {
        get_dp(l + 1, r - 1);
        dp[l][r] += dp[l + 1][r - 1];
    }
    if (ok(l + 2, r, l, l + 1, l, r)) {
        get_dp(l + 2, r);
        dp[l][r] += dp[l + 2][r];
    }
    if (ok(l, r - 2, r - 1, r, l, r)) {
        get_dp(l, r - 2);
        dp[l][r] += dp[l][r - 2];
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ant["="] = "=";
    ant["<"] = ">";
    ant[">"] = "<";
    ant["<="] = ">=";
    ant[">="] = "<=";
    cin >> n >> k;
    n *= 2;
    for (int i = 0; i < k; ++i) {
        int a, b;
        string s;
        cin >> a >> s >> b;
        --a;
        --b;
        g[a].push_back(b);
        z[a].push_back(s);
        g[b].push_back(a);
        z[b].push_back(ant[s]);
    }
    get_dp(0, n - 1);
    cout << dp[0][n - 1] << endl;
    return 0;
}