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

int s, f;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    cin >> s >> f;
    int a[3] = {f, f, f};
    int ans = 0;
    for (; a[0] != s or a[1] != s or a[2] != s ; ++ans) {
        a[ans % 3] = min(a[(ans + 1) % 3] + a[(ans + 2) % 3] - 1, s);
    }

    cout << ans;

    return 0;
}