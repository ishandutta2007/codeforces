#include <bits/stdc++.h>
using namespace std;
#define int long long

int solve(int n, int h, vector<int> &a, vector<int> &p) {
    int curr_h = h;
    int curr_eaten = 0;
    int i = 0;
    while(i < n) {
        // cout << curr_h << ' ' << curr_eaten << ' ' << i << '\n';
        if(a[i] < curr_h) {
            curr_h += a[i]/2;
            i++;
        } else {
            if(curr_eaten == 3) return i;
            curr_h *= p[curr_eaten];
            curr_eaten++;
        }
    }
    return n;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n, h;
        cin >> n >> h;
        vector <int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        vector<vector<int>> p;
        p.push_back({2, 2, 3});
        p.push_back({2, 3, 2});
        p.push_back({3, 2, 2});
        int ans = 0;
        for(int i = 0; i < 3; i++) {
            ans = max(ans, solve(n, h, a, p[i]));
        }
        cout << ans << '\n';
    }
    
    return 0;
}