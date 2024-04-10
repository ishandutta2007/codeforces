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

const int max_n = 1, inf = 1011111111;

long long n, l, r;
map<long long, long long> q;

long long solve(long long n, long long tl, long long tr, long long l, long long r) {
    if (r < tl) {
        return 0;
    }
    if (l > tr) {
        return 0;
    }
    l = max(l, tl);
    r = min(r, tr);
    if (n < 2) {
        return n;
    }
    long long cnt = q[n / 2];
    long long res = solve(n / 2, tl, tl + cnt - 1, l, r);
    res += solve(n % 2, tl + cnt, tl + cnt, l, r);
    res += solve(n / 2, tl + cnt + 1, tr, l, r);
    return res;
}

void dfs(long long n) {
    if (q.count(n)) {
        return;
    }
    if (n < 2) {
        q[n] = 1;
        return;
    }
    dfs(n / 2);
    q[n] = 2 * q[n / 2] + 1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> l >> r;
    dfs(n);
    --l;
    --r;
    cout << solve(n, 0, q[n] - 1, l, r) << endl;
    return 0;
}