#include <set>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

long long n, m, s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m >> s;
    long long a = 1 + (n - 1) % s, b = 1 + (m - 1) % s, x = 1 + (n - 1) / s, y = 1 + (m - 1) / s;
    //cout << a << ' ' << b << ' ' << x << ' ' << y << endl;
    cout << min(n * m, x * y * a * b) << endl;
    return 0;
}