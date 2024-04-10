#include <bits/stdc++.h>

using namespace std;

#define long long long 
#define ve vector
#define vi ve<int>
#define sz(v) ((int)v.size()
#define ii pair<int, int>
#define xx first
#define yy second
#define inf(t) numeric_limits<t>::max()

namespace Solution {

int main() {
    string a, b; cin >> a >> b;

    int t; cin >> t;
    while (t--) {
        cout << a << ' ' << b << '\n';
        string s, r; cin >> s >> r;
        if (s == a) a = r;
        else b = r;
    }
    cout << a << ' ' << b;

    
    return 0;
}}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    return Solution::main();
}