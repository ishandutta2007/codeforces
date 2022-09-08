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

const long long inf = 11111111111111111LL;

long long n;

long long f(long long x) {
    long long res = 0;
    for (long long k = 2; k * k * k <= x; ++k) {
        res += x / (k * k * k);
        if (res > n) {
            return res;
        }
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    long long l = 0, r = inf;
    while (r - l > 1) {
        long long mid = (l + r) / 2;
        if (f(mid) >= n) {
            r = mid;
        } else {
            l = mid;
        }
    }
    if (f(r) == n) {
        cout << r << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}