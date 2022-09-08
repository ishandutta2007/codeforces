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

const int max_n = 31;
const long long inf = 1000111222000111222LL;

int n;
long long x, ans, res, cost[max_n];

bool get_bit(long long x, int pos) {
    return (bool) (x & (1LL << pos));
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> x >> cost[0];
    for (int i = 1; i < n; ++i) {
        cin >> cost[i];
        cost[i] = min(cost[i], cost[i - 1] * 2);
    }
    for (int i = n; i < max_n; ++i) {
        cost[i] = cost[i - 1] * 2;
    }
    ans = inf;
    for (int i = max_n - 1; i >= 0; --i) {
        if (get_bit(x, i) == 0) {
            ans = min(ans, res + cost[i]);
        }
        res += get_bit(x, i) * cost[i];
    }
    ans = min(ans, res);
    cout << ans << endl;
    return 0;
}