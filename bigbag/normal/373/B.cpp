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

const long long inf = 1000000000;

long long get_cnt(long long r) {
    long long ret = 0;
    for (long long i = 10, x = 9, len = 1; ; i *= 10, x *= 10, ++len) {
        if (i <= r) {
            ret += len * x;
        } else {
            ret += len * (r - i / 10 + 1);
            break;
        }
    }
    return ret;
}

long long get_cnt(long long l, long long r) {
    if (l == 1) {
        return get_cnt(r);
    }
    return get_cnt(r) - get_cnt(l - 1);
}

long long w, m, k;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> w >> m >> k;
    if (get_cnt(m, m) * k > w) {
        cout << 0 << endl;
        return 0;
    }
    long long l = m, r = inf * inf;
    while (r - l > 1) {
        long long mid = (l + r) / 2;
        if (get_cnt(m, mid) <= w / k) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l - m + 1 << endl;
    return 0;
}