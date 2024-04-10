#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int a, b, c, d, e, f;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> a >> b >> c >> d >> e >> f;
    int ans = 0;
    if (e > f) {
        int cnt = min(a, d);
        ans += cnt * e;
        a -= cnt;
        d -= cnt;

        cnt = min({b, c, d});
        ans += cnt * f;
        b -= cnt;
        c -= cnt;
        d -= cnt;
    } else {
        int cnt = min({b, c, d});
        ans += cnt * f;
        b -= cnt;
        c -= cnt;
        d -= cnt;

        cnt = min(a, d);
        ans += cnt * e;
        a -= cnt;
        d -= cnt;
    }
    cout << ans << endl;
    return 0;
}