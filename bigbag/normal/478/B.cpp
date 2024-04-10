#include <iostream>
#include <cmath>
#include <string>
#include <set>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

long long n, m, x, y;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    if (m == 1) {
        cout << n * (n - 1) / 2 << " " << n * (n - 1) / 2 << endl;
    } else {
        x = n / m;
        y = n % m;
        cout << y * (x + 1) * x / 2 + (m - y) * x * (x - 1) / 2 << " " << (n - m) * (n - m + 1) / 2<< endl;
    }
    return 0;
}