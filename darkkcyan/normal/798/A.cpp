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

string s, t;

int main() {
    cin >> s;
    rep(i, sz(s)) {
        char o = s[i];
        for (char f = 'a'; f <= 'z'; ++f) {
            if (f == o) continue;
            s[i] = f;
            t = s;
            reverse(t.begin(), t.end());
            if (t == s) {
                cout << "YES";
                exit(0);
            }
        }
        s[i] = o;
    }
    cout << "NO";

    return 0;
}}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    return sol::main();
}