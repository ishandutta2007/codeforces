#include <bits/stdc++.h>

using namespace std;

long long a, b, c;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> a >> b >> c;
    long long ans = 2 * c;
    if (a == b) {
        ans += a + b;
    } else {
        ans += 2 * min(a, b) + 1;
    }
    cout << ans << endl;
    return 0;
}