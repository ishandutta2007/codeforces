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

const int max_n = 222222, mod = 1000000007;

int n, f[max_n], to[max_n], used[max_n], pw[max_n], first[max_n];
int num, q[max_n];
int ans = 1;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    pw[0] = 1;
    for (int i = 1; i < max_n; ++i) {
        pw[i] = (2LL * pw[i - 1]) % mod;
    }
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &to[i]);
        f[to[i]] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        if (f[i] == 0) {
            ++num;
            int cnt = 1;
            int v = i;
            while (used[v] == 0) {
                q[v] = num;
                used[v] = cnt;
                ++cnt;
                v = to[v];
            }
            if (q[v] == num) {
                ans = (1LL * ans * pw[used[v] - 1]) % mod;
                int x = (pw[cnt - used[v]] + mod - 2) % mod;
                ans = (1LL * ans * x) % mod;
            } else {
                ans = (1LL * ans * pw[cnt - 1]) % mod;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (used[i] == 0) {
            int v = i, cnt = 0;
            while (used[v] == 0) {
                used[v] = 1;
                v = to[v];
                ++cnt;
            }
            int x = (pw[cnt] + mod - 2) % mod;
            ans = (1LL * ans * x) % mod;
        }
    }
    cout << ans << endl;
    return 0;
}