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

const int max_n = 777;
const long long inf = 1222333444555LL;

int n, m, a[max_n], res[max_n];
vector<long long> v;
map<long long, int> Q;

int solve(long long x) {
    if (Q.count(x)) {
        return Q[x];
    }
    long long kx = x;
    int res = 0;
    multiset<int> q;
    for (int i = 0; i < n; ++i) {
        x += a[i];
        q.insert(a[i]);
        if (x < 0) {
            x -= *q.begin();
            q.erase(q.begin());
            ++res;
        }
    }
    Q[kx] = res;
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = n; i >= 0; --i) {
        long long l = -inf, r = inf;
        while (r - l > 1) {
            long long mid = (l + r) / 2;
            //if (i == 0) cout << mid << " " << solve(mid) << endl;
            if (solve(mid) > i) {
                l = mid;
            } else {
                r = mid;
            }
        }
        v.push_back(r);
        //cout << i << " " << dp[i] << " " << solve(dp[i]) << endl;
    }
    v.push_back(inf);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < v.size(); ++i) {
        res[i] = solve(v[i]);
        //cout << v[i] << " " << res[i] << endl;
    }
    for (int i = 0; i < m; ++i) {
        long long x;
        scanf("%I64d", &x);
        int l = -1, r = v.size();
        while (r - l > 1) {
            int mid = (l + r) / 2;
            //cout << l << " " << r << "   " << mid << " " << v[mid] << endl;
            if (x >= v[mid]) {
                l = mid;
            } else {
                r = mid;
            }
        }
        printf("%d\n", res[l]);
    }
    return 0;
}