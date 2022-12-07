#include <bits/stdc++.h>
using namespace std;
#define int long long

bool check(int x, vector<int> &v, int d) {
    int needed = 0;
    int n = v.size();
    for(int i = 0; i < x; i++) {
        int temp = d/v[n - 1 - i];
        if(v[n - 1 - i] * temp <= d) temp++;
        needed += temp;
    }
    // cout << x << ' ' << needed << ' ' << n << '\n';
    return needed <= n;
}
 
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
 
    int n, d;
    cin >> n >> d;
    vector <int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int l = 0;
    int r = n;
    int ans = -1;
    while(l <= r) {
        int m = (l + r)/2;
        if(check(m, v, d)) {
            ans = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    cout << ans;
    return 0;
}