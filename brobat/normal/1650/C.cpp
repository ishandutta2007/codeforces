#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v(m, vector<int>(3));
        for(int i = 0; i < m; i++) {
            cin >> v[i][0] >> v[i][1];
            v[i][2] = i + 1;
        }
        vector<pair<int, int>> ans;
        int sum = 0;
        sort(v.begin(), v.end(), [&](vector<int> a, vector<int> b) {
            return a[1] < b[1];
        });
        for(int i = 0; i < 2*n; i++) {
            ans.push_back({v[i][0], v[i][2]});
            sum += v[i][1];
        }
        sort(ans.begin(), ans.end());
        cout << sum << '\n';
        for(int i = 0; i < n; i++) {
            cout << ans[i].second << " " << ans[2*n - i - 1].second << '\n'; 
        }
        cout << '\n';
    }
    
    return 0;
}