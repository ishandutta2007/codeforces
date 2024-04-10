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

    int a, b, c;
    cin >> a >> b >> c;
    int x = min(a, min(b, c));
    int y = max(a, max(b, c));

    int ans = lim<int>::max();
    for (int i = x; i <= y; ++i) ans = min(ans, abs(i - a) + abs(i - b) + abs(i -c));
    cout << ans;

    return 0;
}