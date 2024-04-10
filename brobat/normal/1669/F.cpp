#include <bits/stdc++.h>
using namespace std;
#define int long long

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
        vector <int> p(n);
        p[0] = v[0];
        for(int i = 1; i < n; i++) {
            p[i] = p[i - 1] + v[i];
        }
        int wt = 0;
        int cnt = 0;
        for(int i = n - 1; i >= 0; i--) {
            wt += v[i];
            int x = lower_bound(p.begin(), p.end(), wt) - p.begin();
            if(p[x] == wt && x < i ) {
                cnt = max(cnt, x + 1 + n - i);
            }
        }
        cout << cnt << '\n';
    }
    
    return 0;
}