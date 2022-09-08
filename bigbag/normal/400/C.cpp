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

const int max_n = 111111, inf = 111111111;

long long n, m, a, b, c, p;
long long x[max_n], y[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m >> a >> b >> c >> p;
    for (int i = 0; i < p; ++i) {
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < a % 4; ++i) {
        for (int j = 0; j < p; ++j) {
            long long nx = y[j], ny = 1 + n - x[j];
            x[j] = nx;
            y[j] = ny;
        }
        swap(n, m);
    }
    for (int i = 0; i < b % 2; ++i) {
        for (int j = 0; j < p; ++j) {
            long long nx = x[j], ny = 1 + m - y[j];
            x[j] = nx;
            y[j] = ny;
        }
    }
    for (int i = 0; i < c % 4; ++i) {
        for (int j = 0; j < p; ++j) {
            long long nx = 1 + m - y[j], ny = x[j];
            x[j] = nx;
            y[j] = ny;
        }
        swap(n, m);
    }
    //cout << endl;
    for (int i = 0; i < p; ++i) {
        cout << x[i] << ' ' << y[i] << endl;
    }
    return 0;
}