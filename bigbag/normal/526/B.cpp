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

const int max_n = 11111, inf = 1111111111;

int n, fin, a[max_n], dp[max_n], mx[max_n];

int dfs(int v, int sum, int lev) {
    if (lev == n) {
        mx[v] = 0;
        dp[v] = 0;
        return sum;
    }
    dfs(2 * v, sum + a[2 * v], lev + 1);
    dfs(2 * v + 1, sum + a[2 * v + 1], lev + 1);
    mx[v] = max(mx[2 * v] + a[2 * v], mx[2 * v + 1] + a[2 * v + 1]);
    dp[v] = dp[2 * v] + dp[2 * v + 1];
    dp[v] += max(mx[2 * v] + a[2 * v], mx[2 * v + 1] + a[2 * v + 1]) - min(mx[2 * v] + a[2 * v], mx[2 * v + 1] + a[2 * v + 1]);
    //cout << v << " " << dp[v] << " " << mx[v] << endl;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    fin = (1 << (n + 1));
    for (int i = 2; i < fin; ++i) {
        cin >> a[i];
    }
    dfs(1, 0, 0);
    cout << dp[1] << endl;
    return 0;
}