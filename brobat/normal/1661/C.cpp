#include <bits/stdc++.h>
using namespace std;
#define int long long

int solve(int n, vector <int> &v) {
    int o = 0;
    int t = 0;
    for(int i = 0; i < n; i++) {
        o += (v[i] % 2);
        t += (v[i] / 2);
    }
    if(o >= t) return max(2 * o - 1, t * 2);
    int diff = (t - o)/3;
    int mod = (t - o) % 3;
    o += 2 * diff;
    t -= diff;
    if(mod == 2) {
        o += 2;
        t -= 1;
    }
    return max(2 * o - 1, t * 2);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector <int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        int mx = *max_element(v.begin(), v.end());
        for(int i = 0; i < n; i++) {
            v[i] = mx - v[i];
        }
        int ans = solve(n, v);
        for(int i = 0; i < n; i++) {
            v[i]++;
        }
        ans = min(ans, solve(n, v));
        cout << ans << endl;
    }
    
    return 0;
}