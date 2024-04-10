#include <bits/stdc++.h>

using namespace std;

int t, l, r;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> l >> r;
        if (2 * l > r) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}