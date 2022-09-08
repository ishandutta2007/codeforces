#include <set>
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

const int max_n = 111, inf = 111111111;

int n, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    a[n] = a[0];
    int min1 = inf, poz;
    for (int i = 0; i < n; ++i) {
        if (abs(a[i] - a[i + 1]) < min1) {
            poz = i;
            min1 = abs(a[i] - a[i + 1]);
        }
    }
    if (poz == n - 1) {
        cout << n << ' ' << 1 << endl;
    } else {
        cout << poz + 1 << ' ' << poz + 2 << endl;
    }
    return 0;
}