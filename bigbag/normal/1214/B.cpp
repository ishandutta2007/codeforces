#include <bits/stdc++.h>

using namespace std;

int n, b, g;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> b >> g >> n;
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        if (i <= b && n - i <= g) {
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}