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

const int max_n = 1111, inf = 111111111;

int t;

bool good(int n, int l, int r) {
    if (n % l == 0 || n % r == 0 || l <= n && n <= r) {
        return true;
    }
    if (n >= n % l + l && n % l + l <= r) {
        return true;
    }
    if (n > r && n - l < l) {
        return false;
    }
    if (n < l) {
        return false;
    }
    if (n > r && n - l < l) {
        return false;
    }
    if (l == r && n % l != 0) {
        return false;
    }
    for (int i = l; i <= l + 1000 && i <= r; ++i) {
        if ((r - i) * (n / i) >= n % i) {
            return true;
        }
    }
    return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n, l, r;
        cin >> n >> l >> r;
        if (good(n, l, r)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}