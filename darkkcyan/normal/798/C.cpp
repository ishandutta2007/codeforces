#include <bits/stdc++.h>

using namespace std;

namespace sol {

#define iint long long 
#define ve vector
#define vi ve<int>
#define sz(v) ((int)v.size())
#define ii pair<int, int>
#define xx first
#define yy second
#define inf(t) numeric_limits<t>::max()
#define rep(i,n) for(int i = -1; ++i < n; )

#define maxn 101010
int n;
int a[maxn];

int main() {
    cin >> n;
    rep(i, n) cin >> a[i];

    cout << "YES\n";
    int g = a[0];
    rep(i, n - 1) g = __gcd(g, a[i + 1]);
    if (g > 1) cout << "0", exit(0);
    int c = 0;
    int ans = 0;
    rep(i, n) {
        if (a[i] & 1) ++c;
        else {
            ans += c / 2;
            if (c & 1) ans += 2;
            c = 0;
        }
    }
    ans += c / 2;
    if (c & 1) ans += 2;
    cout << ans;

    return 0;
}}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    return sol::main();
}