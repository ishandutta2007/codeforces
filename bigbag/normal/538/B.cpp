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

const int max_n = 1011111, inf = 1111111111;

int n, dp[max_n], p[max_n];
vector<int> q;

void get(int x) {
    if (x > n) {
        return;
    }
    q.push_back(x);
    get(x * 10);
    get(x * 10 + 1);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    dp[0] = 0;
    get(1);
    for (int i = 1; i <= n; ++i) {
        dp[i] = inf;
        for (int j = 0; j < q.size(); ++j) {
            if (q[j] <= i) {
                if (dp[i] > dp[i - q[j]] + 1) {
                    dp[i] = dp[i - q[j]] + 1;
                    p[i] = q[j];
                }
            }
        }
    }
    cout << dp[n] << endl;
    while (n) {
        cout << p[n] << " ";
        n -= p[n];
    }
    return 0;
}