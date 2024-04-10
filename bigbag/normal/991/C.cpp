#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

long long n;

bool ok(long long x, long long n) {
    long long a = 0, b = 0;
    while (n) {
        long long y = min(n, x);
        a += y;
        n -= y;

        y = n / 10;
        n -= y;
        b += y;
    }
    return a >= b;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    long long l = 0, r = n;
    while (r - l > 1) {
        long long mid = (l + r) / 2;
        if (ok(mid, n)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r << endl;
    return 0;
}