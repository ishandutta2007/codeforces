#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 555, inf = 2000000008;

long long n, x1, y1, x2, y2;

long long f(long long x, long long y) {
    long long c1 = (y + 2) / 2;
    long long c2 = (y + 1) / 2;
    long long q = (x + 1) / 2;
    long long res = (c1 + c2) * q;
    if (x % 2 == 0) {
        res += c1;
    }
    return res;
}

long long solve(long long x1, long long y1, long long x2, long long y2) {
    x1 += inf;
    y1 += inf;
    x2 += inf;
    y2 += inf;
    return f(x2, y2) - f(x1 - 1, y2) - f(x2, y1 - 1) + f(x1 - 1, y1 - 1);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t = 1;
    while (t--) {
        cin >> x1 >> y1 >> x2 >> y2;
        x2 -= x1;
        y2 -= y1;
        x1 = 0;
        y1 = 0;
        long long c1, c2;
        if (x1 % 2 == 0) {
            long long yl = y1, yr = y2;
            if (yl % 2) {
                ++yl;
            }
            if (yr % 2) {
                --yr;
            }
            c1 = (yr - yl + 2) / 2;
        } else {
            long long yl = y1, yr = y2;
            if (yl % 2 == 0) {
                ++yl;
            }
            if (yr % 2 == 0) {
                --yr;
            }
            c1 = (yr - yl + 2) / 2;
        }
        if (x1 % 2) {
            long long yl = y1, yr = y2;
            if (yl % 2) {
                ++yl;
            }
            if (yr % 2) {
                --yr;
            }
            c2 = (yr - yl + 2) / 2;
        } else {
            long long yl = y1, yr = y2;
            if (yl % 2 == 0) {
                ++yl;
            }
            if (yr % 2 == 0) {
                --yr;
            }
            c2 = (yr - yl + 2) / 2;
        }
        //cout << c1 << " " << c2 << endl;
        long long A1, A2;
        if ((x2 - x1) % 2 == 0) {
            A1 = (x2 - x1) / 2 * (c1 + c2) + c1;
        } else {
            A1 = (x2 - x1) / 2 * (c1 + c2) + c1 + c2;
        }
        cout << A1;
    }
    return 0;
}