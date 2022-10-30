#include <bits/stdc++.h>
using namespace std;

const int N = 110000;

int chk[N], dp[N];
vector<int> V[N];

int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        chk[x] = 1;
    }
    for (int i = 2; i <= 100000; i++) {
        for (int j = i; j <= 100000; j += i) V[j].push_back(i);
    }
    int ans = 1;
    for (int i = 1; i <= 100000; i++) {
        if (!chk[i]) continue;
        int cur = 0;
        for (auto j : V[i]) {
            cur = max(cur, dp[j] + 1);
        }
        for (auto j : V[i]) {
            dp[j] = max(dp[j], cur);
        }
        ans = max(ans, cur);
    }
    cout << ans << endl;
    return 0;
}