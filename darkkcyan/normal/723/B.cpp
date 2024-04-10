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

string s, a;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    int n;
    cin >> n >> a;
    for (int i = 0; i < sz(a); ++i) {
        if (a[i] == '_') s += ' ';
        else if (a[i] == '(') s += " ( ";
        else if (a[i] == ')') s += " ) ";
        else s += a[i];
    }

    stringstream ss;
    ss << s;
    int ans[2] = {0};
    int ind = 0;
    while (ss >> a) {
        if (a == "(" or a == ")") ind ^= 1;
        else if (ind == 0) ans[ind] = max(ans[ind], sz(a));
        else ans[ind] ++;
    }

    cout << ans[0] << ' ' << ans[1];

    return 0;
}