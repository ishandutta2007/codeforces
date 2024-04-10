#include <bits/stdc++.h>
#define _FORTIFY_SOURCE 0
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
#define int long long
//#define double long double
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(2*n);
    for (int i=0; i < 2*n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    int ans = (v[n-1] - v[0]) * (v[2*n-1] - v[n]);
    for (int i=1; i+n < 2*n; i++){
        ans = min(ans, (v[2*n-1] - v[0]) * (v[i+n-1]-v[i]));
    }
    cout << ans;
    return 0;
}