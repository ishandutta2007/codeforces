
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

long n, m;

int main() {
    cin >> n >> m;
    if (m >= n) return cout << n, 0;
    long l = 0, r = 2e9;
    n -= m;
    while (l < r) {
        long mid = l + (r - l) / 2;
        long x = (1 + mid) * mid / 2;
        if (x >= n) r = mid;
        else l = mid + 1;
    }
    cout << m + l;
    return 0;
} }

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
    return Solution::main();
}