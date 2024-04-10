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

    int n; string s;
    cin >> n >> s;
    vi ans;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'B') ++cnt;
        else {
            if (cnt) ans.push_back(cnt);
            cnt = 0;
        }
    }
    if (cnt) ans.push_back(cnt);
    cout << ans.size() << '\n';
    for (int i = 0; i < sz(ans); ++i) cout << ans[i] << ' ';

    return 0;
}