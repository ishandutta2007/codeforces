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

const double dia = 20000;

int main() {
    #ifndef ONLINE_JUDGE
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int y = dia / 2;
    #define quit() cout << "NO", clog << __LINE__, exit(0)
    while (n--) {
        int d; string s; cin >> d >> s;
        switch (s[0]) {
            case 'N':
                if (dia / 2 - y < d) quit();
                y += d;
                break;
            case 'S':
                if (y + dia / 2 < d) quit();
                y -= d;
                break;
            default:
                if (y == dia / 2 or y == -dia / 2) quit();
                break;
        }
    }

    if (y != dia / 2) cout << "NO";
    else cout << "YES";

    return 0;
}