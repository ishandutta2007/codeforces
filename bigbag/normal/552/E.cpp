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

const int max_n = 5555, inf = 1111111111;

int n;
long long a[max_n], b[max_n], x[max_n], y[max_n], q[max_n], w[max_n];
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s;
    for (int i = 0; i < s.length(); ++i) {
        a[n] = s[i] - '0';
        ++i;
        if (i < s.length() && s[i] == '*') {
            b[n] = 1;
        }
        ++n;
    }
    x[n - 1] = a[n - 1];
    y[n - 1] = 0;
    for (int i = n - 2; i >= 0; --i) {
        if (b[i]) {
            x[i] = x[i + 1] * a[i];
            y[i] = y[i + 1];
        } else {
            x[i] = a[i];
            y[i] = x[i + 1] + y[i + 1];
        }
    }
    q[0] = a[0];
    w[n - 1] = 0;
    for (int i = 1; i < n; ++i) {
        if (b[i - 1]) {
            q[i] = q[i - 1] * a[i];
            w[i] = w[i - 1];
        } else {
            q[i] = a[i];
            w[i] = q[i - 1] + w[i - 1];
        }
    }
    /*for (int i = 0; i < n; ++i) {
        cout << x[i] << " " << y[i] << endl;
    }
    cout << endl;
    for (int i = 0; i < n; ++i) {
        cout << q[i] << " " << w[i] << endl;
    }
    cout << endl;*/
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        long long v = 0, last = a[i], first = a[i], f = 0;
        for (int j = i; j < n; ++j) {
            if (i == 0) {
                if (j + 1 == n) {
                    ans = max(ans, first * f + v + last);
                } else {
                    if (b[j]) {
                        long long A = (v + first * f + last) * x[j + 1] + y[j + 1];
                        ans = max(ans, A);
                    } else {
                        long long A = first * f + last + x[j + 1] + v + y[j + 1];
                        ans = max(ans, A);
                    }
                }
            } else {
                if (j + 1 == n) {
                    if (b[i - 1]) {
                        long long A = (f * first + v + last) * q[i - 1] + w[i - 1];
                        ans = max(ans, A);
                    } else {
                        long long A = first + f * last + q[i - 1] + v + w[i - 1];
                        ans = max(ans, A);
                    }
                } else {
                    if (b[i - 1] == 1 && b[j] == 1) {
                        long long A = (f * last + v + first) * q[i - 1] * x[j + 1] + w[i - 1] + y[j + 1];
                        ans = max(ans, A);
                    }
                    if (b[i - 1] == 1 && b[j] == 0) {
                        long long A = (f * last + v + first) * q[i - 1] + x[j + 1] + w[i - 1] + y[j + 1];
                        ans = max(ans, A);
                    }
                    if (b[i - 1] == 0 && b[j] == 1) {
                        long long A = (f * last + v + first) * x[j + 1] + q[i - 1] + w[i - 1] + y[j + 1];
                        ans = max(ans, A);
                    }
                    if (b[i - 1] == 0 && b[j] == 0) {
                        long long A = (f * last + v + first) + x[j + 1] + q[i - 1] + w[i - 1] + y[j + 1];
                        ans = max(ans, A);
                    }
                }
            }
            if (b[j]) {
                last *= a[j + 1];
            } else {
                if (f == 0) {
                    first = last;
                    f = 1;
                } else {
                    v += last;
                }
                last = a[j + 1];
            }
        }
    }
    cout << ans << endl;
    return 0;
}