#include <bits/stdc++.h>

using namespace std;

#define fn "main"
#define ve vector
#define vi ve<int>
#define sz(v) ((int)v.size())
#define ii pair<int, int>
#define xx first
#define yy second

int n;
string s;
set<char> se;

int main() {
    #ifndef ONLINE_JUDGE
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> n >> s;
    string t = "ULDR";
    for (int i = 0; i < sz(s); ++i) {
        s[i] = t.find(s[i]);
    }
    int ans = 1;
    for (int i = 0; i < n; ++i) {
        if (se.count(s[i] ^ 2) or (sz(se) == 2 and !se.count(s[i]))) {
            ++ans;
            se.clear();
        }
        se.insert(s[i]);
    }

    cout << ans;

    return 0;
}