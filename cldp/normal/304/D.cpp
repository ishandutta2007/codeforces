#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAXN = 1100;

long long n, m, x, y, a, b;


int find(long long ratio, long long &ans1, long long &ans2) {
    long long c = a * ratio, d = b * ratio;
    if (c & 1) {
        if (c / 2 + x <= n && x >= c / 2 + 1) {
            ans1 = x - c / 2 - 1;
        } else
        if (c / 2 + 1 + x <= n && x >= c / 2) {
            ans1 = x - c / 2;
        } else {
            if (abs(c / 2 - x) < abs(n - 1 - c / 2 - x)) {
                ans1 = 0;
            } else {
                ans1 = n - c;
            }
        }
    } else {
        if (c / 2 + x <= n && x >= c / 2) {
            ans1 = x - c / 2;
        } else {
            if (abs(c / 2 - x) < abs(n - c / 2 - x)) {
                ans1 = 0;
            } else {
                ans1 = n - c;
            }
        }
    }
    
    if (d & 1) {
        if (d / 2 + y <= m && y >= d / 2 + 1) {
            ans2 = y - d / 2 - 1;
        } else
        if (d / 2 + 1 + y <= m && y >= d / 2) {
            ans2 = y - d / 2;
        } else {
            if (abs(d / 2 - y) < abs(m - 1 - d / 2 - y)) {
                ans2 = 0;
            } else {
                ans2 = m - d;
            }
        }
    } else {
        if (d / 2 + y <= m && y >= d / 2) {
            ans2 = y - d / 2;
        } else {
            if (abs(d / 2 - y) < abs(m - d / 2 - y)) {
                ans2 = 0;
            } else {
                ans2 = m - d;
            }
        }
    }
    
    return 0;
}

long long gcd(int a, int b) {
    long long t;
    while (b > 0) {
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main() {
    cin >> n >> m >> x >> y >> a >> b;
    long long tmp = gcd(a, b);
    a = a / tmp;
    b = b / tmp;
    
    long long l = 1, r = min(n / a, m / b) + 1, ratio;
    
    while (l + 1 < r) {
        long long mid = (l + r) >> 1;
        if (a * mid <= n && b * mid <= m) {
            l = mid;
        } else {
            r = mid;
        }
    }
    
    ratio = l;
    
    long long ans1, ans2;
    find(ratio, ans1, ans2);
    
    
    cout << ans1 << " " << ans2 << " " << ans1 + a * ratio << " " << ans2 + b * ratio << endl;
   
    return 0;
}