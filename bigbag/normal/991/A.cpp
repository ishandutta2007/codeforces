#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int a, b, c, n;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> a >> b >> c >> n;
    if (a + b - c < n && a >= c && b >= c) {
        cout << n - a - b + c << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}