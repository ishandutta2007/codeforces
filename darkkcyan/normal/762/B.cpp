#include <bits/stdc++.h>
using namespace std;

#define xx first
#define yy second
#define ii pair<int, int>
#define ve vector
#define vi ve<int>
#define sz(v) ((int)v.size())
#define inf(type) numeric_limits<type>::max()
#define long long long 
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define llog(x) clog << x << endl

namespace Solution {
    
long a, b, c;
ve<long> u, v;
    
int main() {
    cin >> a >> b >> c;
    int n; cin >> n;
    while (n--) {
        long p; string t;
        cin >> p >> t;
        if (t[0] == 'U') u.push_back(p);
        else v.push_back(p);
    }
    
    sort(rall(u));
    sort(rall(v));
    
    int ans1 = 0; long ans2 = 0;
    while (a -- and sz(u)) {
        ans1++;
        ans2 += u.back();
        u.pop_back();
    }
    while (b-- and sz(v)) {
        ++ans1;
        ans2 += v.back();
        v.pop_back();
    }
    
    while (c-- and (sz(u) or sz(v))) {
        ++ans1;
        if (!sz(u)) {
            ans2 += v.back();
            v.pop_back();
        } else if (!sz(v)) {
            ans2 += u.back();
            u.pop_back();
        } else if (v.back() < u.back()) {
            ans2 += v.back();
            v.pop_back();
        } else {
            ans2 += u.back();
            u.pop_back();
        }
    }
    cout << ans1 << ' ' << ans2;
}}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    return Solution::main();
}