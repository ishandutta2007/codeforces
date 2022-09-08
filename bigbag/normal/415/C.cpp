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

int n, k;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k;
    if (n == 1) {
        if (k == 0) {
            cout << 1 << endl;
        } else {
            cout << -1 << endl;
        }
        return 0;
    }
    if (n / 2 > k) {
        cout << -1 << endl;
        return 0;
    }
    if (n == 2) {
        cout << k << ' ' << k * 2 << endl;
        return 0;
    }
    if (n == 3) {
        cout << k << ' ' << k * 2 << ' ' << k * 2 + 1 << endl;
        return 0;
    }
    n -= 2;
    int x = k - n / 2;
    cout << x << ' ' << x * 2 << ' ';
    for (int i = 1; i < n; i += 2) {
        int y = i + 200000002;
        cout << y << ' ' << y + 1 << ' ';
    }
    if (n % 2 != 0) {
        cout << 1000000000 << endl;
    }
    return 0;
}