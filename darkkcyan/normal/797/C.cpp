#include <bits/stdc++.h>

using namespace std;

#define long long long 
#define ve vector
#define vi ve<int>
#define sz(v) ((int)v.size())
#define ii pair<int, int>
#define xx first
#define yy second
#define inf(t) numeric_limits<t>::max()
#define rep(i,n) for (int i = -1; ++i < n; )

namespace sol {
// solution start here
string s, ans;
ve<char> a, b, c;

int main() {
    cin >> s;
    for (int i = sz(s); i--; ) a.push_back(s[i]);
    for (int i = 'a'; i <= 'z'; ++i) {
        for (; sz(c) and c.back() <= i; c.pop_back()) ans += c.back();
        for (; sz(a); a.pop_back()) {
            if (a.back() == i) ans += a.back();
            else c.push_back(a.back());
            b.push_back(a.back());
        }
        for (; sz(b) and b.back() != i; b.pop_back(), c.pop_back()) a.push_back(b.back());
        b.clear();
    }
    for (int i = sz(c); i--; ) ans += c[i];
    cout << ans;

    
    return 0;
}}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    return sol::main();
}