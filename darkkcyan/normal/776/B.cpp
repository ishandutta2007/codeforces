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

#define maxn 101010
bitset<maxn> bs;

int main() {
    int n; cin >> n;
    int cnt = 1;
    for (long i = 1; ++i <= n + 1; ) {
        if (bs[i]) {
            cnt = 2;
            continue;
        }
        for (long f = i * i; f < maxn; f += i) bs[f] = 1;
    }
    cout << cnt << '\n';
    for (int i = 0; ++i <= n; ) cout << (int)bs[i + 1] + 1 << ' ';
    
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