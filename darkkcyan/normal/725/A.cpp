#include <bits/stdc++.h>

using namespace std;

#define ve vector
#define xx first
#define yy second
#define long long long
#define sz(v) ((int)v.size())
#define bb begin()
#define ee end()
#define rbb rbegin()
#define ree rend()
typedef ve<int> vi;
typedef pair<int, int> ii;

int main() {
    #ifndef ONLINE_JUDGE
    #define filename "file"
    freopen(filename".inp", "r", stdin);
    freopen(filename".out", "w", stdout);
    #endif // ONLINE_JUDGE

    int n;
    string s; cin >> n >> s;
    int ans = 0;
    for (int i = sz(s) - 1; i >= 0 and s[i] == '>'; --i, ++ans);
    for (int i = 0; i < sz(s) and s[i] == '<'; ++i, ++ans);
    cout << ans;

    return 0;
}