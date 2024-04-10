#include<bits/stdc++.h>

using namespace std;

#define sz(v) ((int)v.size())
#define long long long 
#define ii pair<int, int>
#define inf(t) numeric_limits<t>::max()
#define xx first
#define yy second

long k, a, b;

int main() {
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    cin >> k >> a >> b;
    long ta = a / k, ma = a % k;
    long tb = b / k, mb = b % k;

    if (ma > 0 and tb == 0) return cout << -1, 0;
    if (mb > 0 and ta == 0) return cout << -1, 0;
    cout << ta + tb;

    return 0;
}