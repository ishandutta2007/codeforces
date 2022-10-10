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

    long n; cin >> n;

    long ans = 1, b = 8;
    for (; n > 0; n >>= 1) {
        if (n & 1) ans = (ans * b) % 10;
        b = (b * b) % 10;
    }

    cout << ans;

    return 0;
}