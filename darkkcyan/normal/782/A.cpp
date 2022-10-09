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

namespace Solution {

int n;
set<int> s;

int main() {

    cin >> n;
    int ans = 0;
    for (int i = -1; ++i < n * 2; ) {
        int x; cin >> x;
        if (s.count(x)) s.erase(x);
        else s.insert(x);
        ans = max(ans, sz(s));
    }
    cout << ans;

    return 0;
}}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    return Solution::main();
}