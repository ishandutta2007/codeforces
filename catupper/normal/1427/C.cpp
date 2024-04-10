#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using Int = long long;
using Real = long double;
using CP = complex<Real>;
using P = pair<Int, Int>;

const Int MOD = 1000000007;
const Int MOD2 = 998244353;
const Int LINF = (1LL << 60);
const int INF = (1000000007);
const Real EPS = 1e-10;
const long double PI = 3.141592653589793238462643383279502884L;

int r, n;
int t[110000], x[110000], y[110000];
int dp[110000];
int mxdp[110000];
int ans;
int dist(int x, int y, int x2, int y2)
{
    return abs(x - x2) + abs(y - y2);
}

int main()
{
    scanf("%d%d", &r, &n);
    for (int i = 0; i < n; i++) {
        dp[i] = -INF;
        scanf("%d%d%d", &t[i], &x[i], &y[i]);
        if (dist(x[i], y[i], 1, 1) <= t[i])
            dp[i] = 1;
        int j = i - 1;
        for (; j >= 0 && t[i] - t[j] <= 1000; j--) {
            if (dist(x[i], y[i], x[j], y[j]) <= t[i] - t[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        if (j >= 0)
            dp[i] = max(dp[i], mxdp[j] + 1);
        mxdp[i] = dp[i];
        if (i)
            mxdp[i] = max(mxdp[i], mxdp[i - 1]);
        ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
    return 0;
}