#include <bits/stdc++.h>

using namespace std;

#define long long long
#define ve vector
#define xx first
#define yy second
#define bb begin()
#define ee end()
#define rbb rbegin()
#define ree rend()
#define sz(v) ((int) v.size())
#define inf(type) (numeric_limits<type>::max() - 10)
typedef ve<int> vi;
typedef pair<int, int> ii;

int main() {
    #ifndef ONLINE_JUDGE
    #define fn "file"
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #undef fn
    #endif // ONLINE_JUDGE

    string s; cin >> s;
    string d = "AEIOUY";

    int ans = 0;
    int last = -1;
    for (int i = 0; i < sz(s); ++i) {
        if (d.find(s[i]) == string::npos) continue;
        ans = max(ans, i - last);
        last = i;
    }
    ans = max(ans, sz(s) - last);
    cout << ans;


    return 0;
}