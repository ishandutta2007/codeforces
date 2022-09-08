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

long long a[3];

long long fun(long long a, long long b, long long c) {
    if (a >= (a + b + c) / 3) {
        return a;
    }
    if (a == b) {
        if (a == 0) {
            return 0;
        }
        long long l = 1, r = a + 1;
        while (r - l > 1) {
            long long mid = (l + r) / 2;
            if (a - mid <= c - 4 * mid) l = mid;
            else r = mid;
        }
        long long res = fun(a - l, b - l, c - 4 * l) + 2 * l;
        return res;
    }
    if (b == c) {
        long long l = 0, r = b + 1;
        while (r - l > 1) {
            long long mid = (l + r) / 2;
            if (a <= b - 3 * mid) l = mid;
            else r = mid;
        }
        if (l == 0) {
            return fun(a, b - 2, c - 1) + 1;
        }
        return fun(a, b - 3 * l, c - 3 * l) + 2 * l;
    }
    long long l = 1, r = c + 1;
    while (r - l > 1) {
        long long mid = (l + r) / 2;
        if (a <= b - mid && b - mid <= c - 2 * mid) l = mid;
        else r = mid;
    }
    long long res = fun(a, b - l, c - 2 * l) + l;
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    cout << fun(a[0], a[1], a[2]) << endl;
    return 0;
}