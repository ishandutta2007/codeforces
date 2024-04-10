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

string w = "Blbsr";
string s;
int cnt[300] = {0};

int main() {
    #ifndef ONLINE_JUDGE
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> s;
    for (int i = 0; i < sz(s); ++i) cnt[s[i]]++;

    int ans = inf(int);
    for (int i = 0; i < sz(w); ++i) ans = min(ans, cnt[w[i]]);
    ans = min(ans, min(cnt['a'] / 2, cnt['u'] / 2));
    cout << ans;

    return 0;
}