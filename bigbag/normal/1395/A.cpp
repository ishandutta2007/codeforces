#include <bits/stdc++.h>

using namespace std;

int t, a, b, c, d;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> a >> b >> c >> d;
        int cnt = a % 2 + b % 2 + c % 2 + d % 2;;
        if (cnt <= 1 || (cnt >= 3 && min({a, b, c}) >= 1)) {
            puts("Yes");
        } else {
            puts("No");
        }
    }
    return 0;
}