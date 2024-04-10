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

const int max_n = 5555;
const long long inf = 1111111111111111111LL;

int n, x, l[max_n], r[max_n];
long long dp[2][2 * max_n];
vector<int> v;

int dist(int x, int l, int r) {
    if (l <= x && x <= r) {
        return 0;
    }
    if (x < l) {
        return l - x;
    }
    return x - r;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> x;
    v.push_back(x);
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
        v.push_back(l[i]);
        v.push_back(r[i]);
    }
    int q1 = 0, q2 = 1;
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i) {
        dp[q1][i] = inf;
    }
    dp[q1][lower_bound(v.begin(), v.end(), x) - v.begin()] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < v.size(); ++j) {
            dp[q2][j] = inf;
        }
        long long mn = inf;
        for (int j = 0; j < v.size(); ++j) {
            mn = min(mn, dp[q1][j] - v[j]);
            dp[q2][j] = min(dp[q2][j], mn + v[j] + dist(v[j], l[i], r[i]));
        }
        mn = inf;
        for (int j = v.size() - 1; j >= 0; --j) {
            mn = min(mn, dp[q1][j] + v[j]);
            dp[q2][j] = min(dp[q2][j], mn - v[j] + dist(v[j], l[i], r[i]));
        }
        swap(q1, q2);
    }
    long long ans = inf;
    for (int i = 0; i < v.size(); ++i) {
        ans = min(ans, dp[q1][i]);
    }
    cout << ans << endl;
    return 0;
}