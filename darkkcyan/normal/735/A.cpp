#include <bits/stdc++.h>

using namespace std;

#define fn "main"
#define long long long
#define ve vector
#define xx first
#define yy second
#define bb begin()
#define ee end()
#define rbb rbegin()
#define ree rend()
#define sz(v) ((int) v.size())
#define inf(type) (numeric_limits<type>::max())
#define vi ve<int>
#define ii pair<int, int>
#define sz(v) ((int) v.size())

int n, k;
string s;

int main() {
    #ifndef ONLINE_JUDGE
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> n >> k >> s;

    int g = s.find('G');
    int t = s.find('T');
    if (abs(g - t) % k) cout << "NO", exit(0);
    int st = g < t ? k : -k;
    for (; g < sz(s) and g != t; g += st) {
        if (s[g] == '#') cout << "NO", exit(0);
    }
    cout << "YES";

    return 0;
}