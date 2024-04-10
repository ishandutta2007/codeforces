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
#define inf(type) (numeric_limits<type>::max() - 10)
#define vi ve<int>
#define ii pair<int, int>

long k2, k3, k5, k6;

int main() {
    #ifndef ONLINE_JUDGE
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> k2 >> k3 >> k5 >> k6;

    long ans = 0;
    for (; k2 > 0 and k5 > 0 and k6 > 0; --k2, --k5, --k6) ans += 256;
    for (; k2 > 0 and k3 > 0; --k2, --k3) ans += 32;
    cout << ans;


    return 0;
}