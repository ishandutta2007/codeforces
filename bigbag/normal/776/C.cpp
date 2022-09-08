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
const long long inf = 1011111111111111LL;

int n, k;
int a[max_n];
long long ans, sum[max_n];
map<long long, int> q;
vector<long long> all;

void get_all() {
    if (k == 1) {
        all.push_back(1);
    } else if (k == -1) {
        all.push_back(-1);
        all.push_back(1);
    } else {
        long long x = 1;
        while (x <= inf) {
            all.push_back(x);
            x *= k;
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        sum[i] = a[i] + sum[i - 1];
    }
    get_all();
    q[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < all.size(); ++j) {
            long long y = sum[i] - all[j];
            if (q.count(y)) {
                ans += q[y];
            }
        }
        ++q[sum[i]];
    }
    printf("%lld\n", ans);
    return 0;
}