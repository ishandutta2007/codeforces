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

const int max_n = 2222, sd = 222, inf = 1111111111;

int myabs(int x) {
    if (x < 0) {
        return -x;
    }
    return x;
}

int gcd(int a, int b) {
    a = myabs(a);
    b = myabs(b);
    while (a != 0 && b != 0) {
        int k = a;
        a = b;
        b = k % b;
    }
    return a + b;
}

bool is_in(int x, int y) {
    return 0 <= x && 0 <= y && x < max_n && y < max_n;
}

int n, x[max_n], y[max_n], a[max_n][max_n];
long long ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    if (n < 3) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
        x[i] += sd;
        y[i] += sd;
        a[x[i]][y[i]] = 1;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int g = gcd(x[j] - x[i], y[j] - y[i]);
            int sdx = (x[j] - x[i]) / g;
            int sdy = (y[j] - y[i]) / g;
            for (int k = 1; k < sd; ++k) {
                int xx = x[i] + sdx * k;
                int yy = y[i] + sdy * k;
                if (xx == x[i] && yy == y[i]) {
                    continue;
                }
                if (xx == x[j] && yy == y[j]) {
                    continue;
                }
                if (is_in(xx, yy)) {
                    ans += a[xx][yy];
                    /*if (a[xx][yy]) {
                        cout << i << " " << j << " - " << xx - sd << " " << yy - sd << endl;
                    }*/
                } else {
                    break;
                }
            }
            for (int k = -1; k > -sd; --k) {
                int xx = x[i] + sdx * k;
                int yy = y[i] + sdy * k;
                if (xx == x[i] && yy == y[i]) {
                    continue;
                }
                if (xx == x[j] && yy == y[j]) {
                    continue;
                }
                if (is_in(xx, yy)) {
                    ans += a[xx][yy];
                    /*if (a[xx][yy]) {
                        cout << i << " " << j << " - " << xx - sd << " " << yy - sd << endl;
                    }*/
                } else {
                    break;
                }
            }
        }
    }
    //cout << ans << endl;
    ans /= 3;
    long long N = n;
    long long q = (N * (N - 1) * (N - 2)) / 6;
    cout << q - ans << endl;
    return 0;
}