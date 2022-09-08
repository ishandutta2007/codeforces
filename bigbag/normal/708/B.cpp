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

const long long max_n = 1, inf = 1111111111;

long long a, b, c, d, x, y;
string s;

long long f(long long x) {
    for (long long i = 1; (i * (i - 1)) / 2 <= x; ++i) {
        if ((i * (i - 1)) / 2 == x) {
            return i;
        }
    }
    return -1;
}

void solve(long long x, long long y, long long b) {
    if (x == 0 && y == 0) {
        return;
    }
    if (x == 0) {
        printf("1");
        solve(x, y - 1, b);
        return;
    }
    if (b - y >= 0) {
        printf("0");
        solve(x - 1, y, b - y);
    } else {
        printf("1");
        solve(x, y - 1, b);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> a >> b >> c >> d;
    x = f(a);
    y = f(d);
    if (a == 0) {
        if (y != -1 && b == 0 && c == 0) {
            for (int i = 0; i < y; ++i) {
                printf("1");
            }
            printf("\n");
            return 0;
        }
    }
    if (d == 0) {
        if (x != -1 && b == 0 && c == 0) {
            for (int i = 0; i < x; ++i) {
                printf("0");
            }
            printf("\n");
            return 0;
        }
    }
    if (x == -1 || y == -1) {
        printf("Impossible\n");
        return 0;
    }
    if (a + b + c + d != (x + y) * (x + y - 1) / 2) {
        printf("Impossible\n");
        return 0;
    }
    if (b > x * y) {
        printf("Impossible\n");
        return 0;
    }
    solve(x, y, b);
    return 0;
}