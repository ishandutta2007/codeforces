
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

namespace Solution {

map<char, int> m = {
    {'T', 4},
    {'C', 6},
    {'O', 8},
    {'D', 12},
    {'I', 20}
};

int main() {

    int n; cin >> n;
    long ans = 0;
    while (n--) {
        string s; cin >> s;
        ans += m[s[0]];
    }

    cout << ans;

    return 0;
} }

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
    return Solution::main();
}