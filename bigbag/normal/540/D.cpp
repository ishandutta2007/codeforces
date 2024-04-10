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

const int max_n = 111, inf = 1111111111;

int a, b, c, f[max_n][max_n][max_n][3];
double dp[max_n][max_n][max_n][3];

int cn2(int n) {
    return (n * (n - 1)) / 2;
}

double get_dp(int a, int b, int c, int poz) {
    if (a < 0 || b < 0 || c < 0) {
        return 0;
    }
    int q[3];
    q[0] = a;
    q[1] = b;
    q[2] = c;
    int sum = a + b + c - q[poz];
    if (q[poz] == 0) {
        //cout << a << " " << b << " " << c << "  " << poz << "  !-!  " << 0 << endl;
        return 0;
    }
    if (sum == 0) {
        //cout << a << " " << b << " " << c << "  " << poz << "  @-@  " << 1 << endl;
        return 1;
    }
    if (f[a][b][c][poz]) {
        return dp[a][b][c][poz];
    }
    f[a][b][c][poz] = 1;
    double all = cn2(a + b + c);
    double qq1 = (a * c) * get_dp(a - 1, b, c, poz);
    double qq2 = (a * b) * get_dp(a, b - 1, c, poz);
    double qq3 = (b * c) * get_dp(a, b, c - 1, poz);
    double qq = (qq1 + qq2 + qq3) / all;
    double r = (cn2(a) + cn2(b) + cn2(c)) / all;
    qq /= (1 - r);
    dp[a][b][c][poz] = qq;
    //cout << a << " " << b << " " << c << "  " << poz << "  -  " << qq1 << " " << qq2 << " " << qq3 << "  res = " << qq << endl;
    return qq;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> a >> b >> c;
    printf("%.15f ", get_dp(a, b, c, 0));
    printf("%.15f ", get_dp(a, b, c, 1));
    printf("%.15f\n", get_dp(a, b, c, 2));
    return 0;
}