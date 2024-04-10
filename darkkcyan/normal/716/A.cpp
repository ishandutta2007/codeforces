#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#define log(msg) clog << __LINE__ << ": " << msg
#else
#define log(msg)
#endif

#define _ << ' ' <<
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

    int n, c;
    cin >> n >> c;
    int ans = 1;
    int a, b; cin >> a;
    for (int i = 1; i < n; ++i) {
        cin >> b;
        if (b - a <= c) ++ans;
        else ans = 1;
        a = b;
    }
    cout << ans;

    return 0;
}