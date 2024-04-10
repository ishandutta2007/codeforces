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

int n;
string s;
vi a, nxt;

int main() {
    #ifndef ONLINE_JUDGE
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        if (i == 0 or s[i] != s[i - 1]) a.push_back(0);
        ++a.back();
    }

    nxt.resize(sz(a));
    for (int i = 0; i < sz(a); ++i) nxt[i] = i + 1;
    nxt[sz(a) - 1] = 0;
    int i = 0;
    int am = a[0];
    while (true) {
        int f = nxt[i];
        if (i == f) break;
        if ((i + f) % 2 == 0) {
            a[i] += a[f];
            am += a[f];
            nxt[i] = nxt[f];
        } else {
            int t = min(am, a[f]);
            a[f] -= t;
            am -= t;
            if (a[f] == 0) nxt[i] = nxt[f];
        }
        if (am == 0) {
            i = nxt[i];
            am = a[i];
        }
    }

    string ans = "RD";
    if (s[0] == 'D') swap(ans[0], ans[1]);
    printf("%c", ans[i & 1]);

    return 0;
}