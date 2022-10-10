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

long n, a, b, c;

int main() {
    #ifndef ONLINE_JUDGE
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> n >> a >> b >> c;
    switch (n % 4) {
    case 0:
        cout << 0;
        break;
    case 1:
        cout << min(a * 3, min(a + b, c));
        break;
    case 2:
        cout << min(a * 2, min(b, 2 * c));
        break;
    case 3:
        cout << min(a, min(b + c, 3 * c));
        break;
    }

    return 0;
}