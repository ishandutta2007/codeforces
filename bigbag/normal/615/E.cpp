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

const int max_n = 1, inf = 1000000000;

long long n, x, y;

long long f(long long x) {
    return 1 + (x * (x + 1)) * 3;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    if (n == 0) {
        cout << "0 0" << endl;
        return 0;
    }
    long long l = 0, r = inf;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (f(mid) <= n) {
            l = mid;
        } else {
            r = mid;
        }
    }
    n -= f(l);
    x = 1 + 2 * (r - 1);
    y = 2;
    ++r;
    //cout << r << " " << n << endl;
    int q;
    q = min(n, r - 2);
    x -= q;
    y += 2 * q;
    n -= q;
    if (n == 0) {
        cout << x << " " << y << endl;
        return 0;
    }

    q = min(n, r - 1);
    x -= 2 * q;
    n -= q;
    if (n == 0) {
        cout << x << " " << y << endl;
        return 0;
    }

    q = min(n, r - 1);
    x -= q;
    y -= 2 * q;
    n -= q;
    if (n == 0) {
        cout << x << " " << y << endl;
        return 0;
    }

    q = min(n, r - 1);
    x += q;
    y -= 2 * q;
    n -= q;
    if (n == 0) {
        cout << x << " " << y << endl;
        return 0;
    }

    q = min(n, r - 1);
    x += 2 * q;
    n -= q;
    if (n == 0) {
        cout << x << " " << y << endl;
        return 0;
    }

    q = min(n, r - 1);
    x += q;
    y += 2 * q;
    n -= q;
    if (n == 0) {
        cout << x << " " << y << endl;
        return 0;
    }
    return 0;
}