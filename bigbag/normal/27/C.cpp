#include <set>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 111111, inf = 111111111;

int n, a[max_n], num[max_n], num1[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    num[n] = inf;
    num1[n] = inf;
    num[n - 1] = n;
    num1[n - 1] = n;
    if (a[n - 1] <= a[n]) {
        num[n - 1] = inf;
    }
    if (a[n - 1] >= a[n]) {
        num1[n - 1] = inf;
    }
    for (int i = n - 2; i > 0; --i) {
        num[i] = inf;
        num1[i] = inf;
        if (a[i] < a[i + 1]) {
            num1[i] = i + 1;
        }
        if (a[i] > a[i + 1]) {
            num[i] = i + 1;
        }
        if (num[i] == inf) {
            int q = i + 1;
            while (q <= n && a[i] <= a[q]) {
                if (q == inf) {
                    break;
                }
                q = num[q];
            }
            num[i] = q;
        }
        if (num1[i] == inf) {
            int q = i + 1;
            while (q <= n && a[i] >= a[q]) {
                if (q == inf) {
                    break;
                }
                q = num1[q];
            }
            num1[i] = q;
        }
    }
    /*for (int i = 1; i <= n; ++i) {
        cout << num[i] << ' ' << num1[i] << endl;
    }
    while (1);*/
    for (int i = 1; i <= n; ++i) {
        int x, y;
        x = y = inf;
        x = num1[i];
        if (x != inf) {
            y = num[x];
        }
        if (x != inf && y != inf) {
            cout << 3 << endl << i << ' ' << x << ' ' << y << endl;
            return 0;
        }
        x = y = inf;
        x = num[i];
        if (x != inf) {
            y = num1[x];
        }
        if (x != inf && y != inf) {
            cout << 3 << endl << i << ' ' << x << ' ' << y << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}