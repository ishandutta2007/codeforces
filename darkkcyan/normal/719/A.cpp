#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#define log(msg) clog << __LINE__ << ": " << msg
#else
#define log(msg)
#endif

#define _ << ' ' <<
#define lim numeric_limits
#define long long long
#define ve vector
#define vi ve<int>
#define sz(v) ((int) v.size())
#define ii pair<int, int>
#define xx first
#define yy second
#define bb begin()
#define ee end()
#define rbb rbegin()
#define ree rend()

int main() {
    #ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    int n; cin >> n;
    int a, b;
    cin >> a;
    if (n == 1) {
        if (a == 0) return cout << "UP", 0;
        if (a == 15) return cout << "DOWN", 0;
        return cout << -1, 0;
    }

    int sign = 0;
    for (int i = 1; i < n; ++i) {
        cin >> b;
        if (abs(a - b) != 1) return cout << -1, 0;
        if (sign == 0) if (a > b) sign = -1; else sign = 1;
        if (b != a + sign) return cout << -1, 0;
        if (b == 0 or b == 15) sign *= -1;
        a = b;
    }

    if (sign == 1) cout << "UP";
    else cout << "DOWN";

    return 0;
}