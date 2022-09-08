#include <set>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const long long inf = 2000000010LL;

long long a, b, x, y;

long long gcd(long long a, long long b) {
    while (a != 0 && b != 0) {
        long long k = a;
        a = b;
        b = k % b;
    }
    return a + b;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> a >> b >> x >> y;
    long long gc = gcd(x, y);
    x /= gc;
    y /= gc;
    if (a < x || b < y) {
        cout << "0 0\n";
        return 0;
    }
    long long l = 1, r = inf;
    while (r - l > 1) {
        long long mid = (l + r) / 2;
        long long a1 = x * mid, b1 = y * mid;
        if (a1 <= a && b1 <= b) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << x * l << ' ' << y * l;
    return 0;
}