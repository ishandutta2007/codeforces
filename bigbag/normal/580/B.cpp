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

const int max_n = 111111, inf = 1111111111;

int n, d;
long long ans, sum[max_n];
pair<int, int> a[max_n];

long long get_sum(int l, int r) {
    if (l == 0) {
        return sum[r];
    }
    return sum[r] - sum[l - 1];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &d);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i].first, &a[i].second);
    }
    sort(a, a + n);
    sum[0] = a[0].second;
    for (int i = 1; i < n; ++i) {
        sum[i] = sum[i - 1] + a[i].second;
    }
    for (int i = 0; i < n; ++i) {
        int l = i, r = n;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (a[mid].first - a[i].first < d) {
                l = mid;
            } else {
                r = mid;
            }
        }
        ans = max(ans, get_sum(i, l));
    }
    cout << ans << endl;
    return 0;
}