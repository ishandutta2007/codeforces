#include <map>
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

const int max_n = 1111, inf = 111111111;

int n, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int l = 0, r = n - 1, x[2], f = 0;
    x[0] = x[1] = 0;
    while (l <= r) {
        if (a[l] > a[r]) {
            x[f] += a[l];
            ++l;
        } else {
            x[f] += a[r];
            --r;
        }
        f = (f + 1) % 2;
    }
    cout << x[0] << ' ' << x[1] << endl;
    return 0;
}