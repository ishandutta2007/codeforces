#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> v(n);
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            int l = (i + 1)/(x + 1) + 1;
            int r = x == 0 ? n : (i + 1)/x;
            // cout << l << " " << r << '\n';
            v[i] = {l, r, i};
        }
        sort(v.begin(), v.end(), [&](vector <int> a, vector <int> b) {
            if(a[1] == b[1]) return a[0] < b[0];
            return a[1] < b[1];
        });
        set <int> left;
        for(int i = 0; i < n; i++) {
            left.insert(i + 1);
        }
        vector <int> ans(n);
        for(int i = 0; i < n; i++) {
            auto t = left.lower_bound(v[i][0]);
            ans[v[i][2]] = *t;
            left.erase(t);
        }
        for(auto i : ans) cout << i << " ";
        cout << '\n';
    }
    
    return 0;
}