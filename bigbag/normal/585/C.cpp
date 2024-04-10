#include <map>
#include <bitset>
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

const long long inf = 1111111111111111111LL;

long long a, b;

bool get_bit(long long x, int poz) {
    return (bool) (x & (1LL << poz));
}

bitset<133> pr(long long a, long long b) {
    bitset<133> res = 0, q = 0, qq = 0;
    for (int i = 0; i < 63; ++i) {
        qq[i] = get_bit(a, i);
    }
    for (int i = 0; i < 63; ++i) {
        if (get_bit(b, i)) {
            q = qq << i;
            int p = 0;
            for (int j = 0; j < 133; ++j) {
                int x = res[j] + q[j] + p;
                p = x / 2;
                res[j] = x % 2;
            }
        }
    }
    //cout << a << " " << b << " = " << res << endl;
    return res;
}

int cmp(long long a1, long long b1, long long a2, long long b2) {
    bitset<133> q1 = pr(a1, b2), q2 = pr(a2, b1);
    if (q1 == q2) {
        return 0;
    }
    for (int i = 132; i >= 0; --i) {
        if (q1[i] != q2[i]) {
            if (q1[i] < q2[i]) {
                return -1;
            }
            return 1;
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //bitset<77> q;
    //cout << q << endl;
    //q = 999999999999999999LL;
    //cout << q << endl;
    //return 0;
    cin >> a >> b;
    swap(a, b);
    if (__gcd(a, b) > 1) {
        cout << "Impossible" << endl;
        return 0;
    }
    //cout << a << " " << b << endl;
    long long xl = 0, yl = 1, xx = 1, yy = 1, xr = 1, yr = 0, Q = 0;
    while (true) {
        //cout << endl << xx << " " << yy << endl;
        //cout << a << " " << b << endl;
        if (xx == a && yy == b) {
            break;
        }
        if (cmp(xx, yy, a, b) == -1) {
            long long l = 1, r = inf / max(xr, yr) + 1;
            while (r - l > 1) {
                long long mid = (l + r) / 2;
                if (xx + mid * xr <= a && yy + mid * yr <= b && cmp(xx + mid * xr, yy + mid * yr, a, b) <= 0) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            if (xx + (l + 1) * xr <= a && yy + (l + 1) * yr <= b && cmp(xx + l * xr, yy + l * yr, a, b) == -1) {
                ++l;
            }
            cout << l << "B";
            xl = xx + (l - 1) * xr;
            yl = yy + (l - 1) * yr;
            xx += l * xr;
            yy += l * yr;
        } else {
            long long l = 1, r = inf / max(xl, yl) + 1;
            while (r - l > 1) {
                long long mid = (l + r) / 2;
                if (xx + mid * xl <= a && yy + mid * yl <= b && cmp(xx + mid * xl, yy + mid * yl, a, b) >= 0) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            //cout << xx + l * xl << " " << yy + l * yl << " " << a <<  " " << b << endl;
            if (xx + (l + 1) * xl <= a && yy + (l + 1) * yl <= b && cmp(xx + l * xl, yy + l * yl, a, b) == 1) {
                ++l;
            }
            cout << l << "A";
            xr = xx + (l - 1) * xl;
            yr = yy + (l - 1) * yl;
            xx += l * xl;
            yy += l * yl;
        }
    }
    return 0;
}