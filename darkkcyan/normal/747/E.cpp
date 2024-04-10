#include <bits/stdc++.h>

using namespace std;

#define fn "main"
#define long long long
#define ve vector
#define vi ve<int>
#define xx first
#define yy second
#define sz(v) ((int) v.size())
#define inf(type) (numeric_limits<type>::max())
#define ii pair<int, int>
#define sz(v) ((int) v.size())

string s;
stringstream ss;

ve<string> ans;
void process(int lv) {
    while (sz(ans) <= lv) ans.push_back("");
    string t; ss >> t;
    ans[lv] += t + " ";
    int cc; ss >> cc;
    while (cc--) {
        process(lv + 1);
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> s;
    for (int i = 0; i < sz(s); ++i) if (s[i] == ',') s[i] = ' ';
    ss << s;

    while (ss.rdbuf()->in_avail()) process(0);

    cout << sz(ans) << '\n';
    for (int i = 0; i < sz(ans); ++i) cout << ans[i] << '\n';

    return 0;
}