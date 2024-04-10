#include <bits/stdc++.h>

using namespace std;

const int max_n = 300333, inf = 1000111222;

int n, dp[max_n], cnt[max_n], last[max_n], z[max_n], cur;
bool a[max_n];
vector<int> g[max_n], d[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int y = 1; y < max_n; ++y) {
        for (int x = y; x < max_n; x += y) {
            d[x].push_back(y);
        }
    }
    for (int i = 2; i < max_n; ++i) {
        z[i] += 1;
        for (int x = 2 * i; x < max_n; x += i) {
            z[x] -= z[i];
        }
        /*if (i < 20) {
            cout << i << " " << z[i] << endl;
        }*/
    }
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        a[x] = 1;
    }
    for (int y = 1; y < max_n; ++y) {
        int tot = 0;
        ++cur;
        for (int k = 1; k * y < max_n; ++k) {
            if (a[k * y]) {
                // add k
                ++tot;
                for (int x : d[k]) {
                    if (last[x] != cur) {
                        last[x] = cur;
                        cnt[x] = 0;
                    }
                    ++cnt[x];
                }
            }
        }
        for (int k = 1; k * y < max_n; ++k) {
            int sum = 0;
            for (int x : d[k]) {
                if (x != 1 && last[x] == cur) {
                    sum += z[x] * cnt[x];
                }
            }
            if (sum < tot) {
                g[k * y].push_back(y);
            }
        }
    }
    queue<int> q;
    for (int i = 0; i < max_n; ++i) {
        if (a[i]) {
            dp[i] = 1;
            q.push(i);
        }
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int to : g[v]) {
            //cout << v << " -> " << to << endl;
            if (dp[to] == 0) {
                dp[to] = dp[v] + 1;
                q.push(to);
            }
        }
    }
    if (dp[1] == 0) {
        printf("-1\n");
    } else {
        printf("%d\n", dp[1]);
    }
    return 0;
}