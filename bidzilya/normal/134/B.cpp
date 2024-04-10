#include <cstdio>

#include <string>
#include <iostream>
using namespace std;

int n;

int gcd(int x, int y) {
    while (x > 0 && y > 0)  
        if (x >= y)
            x %= y;
        else
            y %= x;
    return (x + y);
}

int egcd(int x, int y) {
    int res = 0;
    while (x != y) {
        if (y > x) swap(x, y);
        int k = x - y;
        k /= y;
        if (k * y < x - y) ++k;
        res += k;
        x -= k * y;
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    int ans = 1e9;
    for (int i = 1; i <= n; ++i)
        if (gcd(i, n) == 1) {
            ans = min(ans, egcd(i, n));
        }
    cout << ans << endl;
    return 0;
}