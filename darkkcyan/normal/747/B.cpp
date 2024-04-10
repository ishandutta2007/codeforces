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


int main() {
    #ifndef ONLINE_JUDGE
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #endif // ONLINE_JUDGE

    int n; string s; cin >> n >> s;
    #define quit() cout << "===", exit(0)
    if (n % 4) quit();
    int ac = count(s.begin(), s.end(), 'A');
    int cc = count(s.begin(), s.end(), 'C');
    int gc = count(s.begin(), s.end(), 'G');
    int tc = count(s.begin(), s.end(), 'T');
    int l = n / 4;
    if (ac > l or cc > l or gc > l or tc > l) quit();
    string t = string(l - ac, 'A') + string(l - cc, 'C') + string(l - gc, 'G') + string(l - tc, 'T');
    int i = 0, f = 0;
    for (;i < n; ++i) {
        if (s[i] == '?') s[i] = t[f++];
    }

    cout << s;

    return 0;
}