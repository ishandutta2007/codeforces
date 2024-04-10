#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int n, a, b;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    while (n--) {
        cin >> a >> b;
        long long x = b / a;
        long long y = x + 1;
        long long cy = b % a;
        long long cx = a - cy;
        long long ans = cx * x * x + cy * y * y;
        cout << ans << "\n";
    }
    return 0;
}