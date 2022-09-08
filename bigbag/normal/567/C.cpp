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

const int max_n = 222222, inf = 1111111111;

int n, k, a[max_n], dp[max_n];
long long ans = 0;
map<int, long long> m;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = n - 1; i >= 0; --i) {
        if (-inf < 1LL * a[i] * k && 1LL * a[i] * k < inf) {
            dp[i] = m[a[i] * k];
        }
        ++m[a[i]];
    }
    m.clear();
    for (int i = n - 1; i >= 0; --i) {
        if (1LL * a[i] * k < inf) {
            ans += m[a[i] * k];
        }
        m[a[i]] += dp[i];
    }
    m.clear();
    cout << ans << endl;
    return 0;
}