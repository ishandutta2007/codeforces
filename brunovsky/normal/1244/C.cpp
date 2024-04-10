#include <bits/stdc++.h>

using namespace std;

#define long int64_t
#define bigint __int128_t

// *****

long gcd(long a, long b, long& x, long& y) {
    long xn = 1, yn = 0;
    x = 0, y = 1;
    while (a != 0) {
        long q = b / a;
        b = b % a;
        x = x - q * xn, y = y - q * yn;
        swap(a, b), swap(x, xn), swap(y, yn);
    }
    if (b < 0) {
        b = -b, x = -x, y = -y;
    }
    return b;
}

auto solve() {
    long n, p, w, d;
    cin >> n >> p >> w >> d;
    long a, b;
    long g = gcd(w, d, a, b);
    // aw + bd = g
    if (p % g != 0) {
        cout << -1 << endl;
        return;
    }
    bigint k = p / g, u = d / g, v = w / g; // u < v
    // can set x=ka+mu, y=kb-mv
    // need x>=0,y>=0 ==> -ka/u <= m <= kb/v
    // need x+y<=n ==> (u-v)m <= n-k(a+b) <==> (v-u)m >= k(a+b)-n
    bigint lo = a >= 0 ? -k * a / u : (-k * a + (u - 1)) / u;
    bigint hi = b >= 0 ? k * b / v : (k * b - (v - 1)) / v;
    assert(u < v);
    long m = LLONG_MIN;
    if (lo <= hi) {
        // (v-u)m >= k(a+b)-n
        bigint num = k * (a + b) - n;
        if (num < 0) {
            bigint minm = num / (v - u);
            if (minm <= hi) {
                m = max(lo, minm);
            }
        } else {
            bigint minm = (num + (v - u - 1)) / (v - u);
            if (minm <= hi) {
                m = max(lo, minm);
            }
        }
    }
    if (m == LLONG_MIN) {
        cout << -1 << endl;
    } else {
        long x = k * a + m * u, y = k * b - m * v, z = n - x - y;
        assert(x >= 0 && y >= 0);
        assert(x + y <= n);
        assert(x * w + y * d == p);
        cout << x << ' ' << y << ' ' << z << endl;
    }
}

// *****

int main() {
    setbuf(stdout, nullptr);
    solve();
    return 0;
}