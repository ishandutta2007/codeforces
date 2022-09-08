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

const int max_n = 111111;
const long long inf = 1111111111111111111LL;

int n, m, a[max_n];
long long ans, res, sum[max_n], X[max_n];
vector<long long> v[max_n];

int my_abs(int x) {
    if (x < 0) {
        return -x;
    }
    return x;
}

long long get_sum(int l, int r) {
    if (l == 0) {
        return sum[r];
    }
    return sum[r] - sum[l - 1];
}

long long fun(long long x, long long c1, long long c2) {
    //cout << x << " " << c1 << " " << c2 << endl;
    return x * c1 - get_sum(0, c1 - 1) + get_sum(c1, c1 + c2 - 1) - c2 * x;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &m, &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if (i) {
            res += my_abs(a[i] - a[i - 1]);
            if (a[i] != a[i - 1]) {
                v[a[i]].push_back(a[i - 1]);
                v[a[i - 1]].push_back(a[i]);
                X[a[i]] += my_abs(a[i] - a[i - 1]);
                X[a[i - 1]] += my_abs(a[i] - a[i - 1]);
            }
        }
    }
    ans = res;
    for (int i = 1; i <= m; ++i) {
        if (v[i].size()) {
            //cout << i << " " << v[i].size() << endl;
            sort(v[i].begin(), v[i].end());
            sum[0] = v[i][0];
            for (int j = 1; j < v[i].size(); ++j) {
                sum[j] = sum[j - 1] + v[i][j];
            }
            int l = max(0, (int) v[i].size() / 2 - 5), r = min(v[i].size() - 1, v[i].size() / 2 + 5);
            /*while (r - l > 5) {
                int mid = (l + r) / 2;
                if (fun(v[i][mid], mid + 1, v[i].size() - mid - 1) >= fun(v[i][mid + 1], mid + 2, v[i].size() - mid - 2)) {
                    l = mid;
                } else {
                    r = mid;
                }
            }*/
            for (int j = l; j <= r; ++j) {
                ans = min(ans, res - X[i] + fun(v[i][j], j + 1, v[i].size() - j - 1));
            }
        }
    }
    printf("%I64d\n", ans);
    return 0;
}