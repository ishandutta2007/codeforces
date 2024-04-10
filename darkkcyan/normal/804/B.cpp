#include <bits/stdc++.h>

using namespace std;

#define llong long long
#define ve vector
#define vi ve<int>
#define sz(v) ((int)v.size())
#define ii pair<int, int>
#define xx first
#define yy second
#define inf(t) numeric_limits<t>::max()
#define rep(i,n) for (int i = -1; ++i < (n); )
#define rep1(i,n) for (int i = 0; ++i <= (n); )

namespace sol {
#define mod ((llong) 1e9 + 7)

string s;

int main() {
    cin >> s;
    llong ans = 0;
    llong cur = 0;
    for (int i = sz(s); i--; ) {
        char c = s[i];
        if (c == 'b') ++cur;
        else {
            ans += cur;
            cur *= 2;
            cur %= mod;
            ans %= mod;
        }
    }
    cout << ans;

    return 0;
}}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    return sol::main();
}