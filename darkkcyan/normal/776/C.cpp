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

int n;
long k;
map<long, int> ma;

int main() {
    cin >> n >> k;
    clog << n << ' ' << k << endl;
    ma[0] = 1;
    long sum = 0;
    long ans = 0;
    for (int i = -1; ++i < n; ) {
        int t; cin >> t;
        sum += (long)t;
        int time = 0;
        for (long p = 1; p <= 1e16; p *= k) {
            ++time;
            if (k == 1 and time > 1 or k == -1 and time > 2) break;
            if (ma.count(sum - p)) {
                ans += ma[sum - p];
            }
        }
        ma[sum]++;
    }
    cout << ans;
    
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