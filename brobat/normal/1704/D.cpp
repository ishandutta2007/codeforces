#include <bits/stdc++.h>
using namespace std;
#define int long long

int ans;

bool can_swap(vector <int> &a, vector <int> &b) {
    int n = a.size();
    int x = 0;
    for(int i = 0; i < n - 1; i++) {
        int diff = a[i] - b[i];
        x += diff;
        a[i] -= diff;
        a[i + 1] += diff;
    }
    if(x != 0) ans = abs(x);
    return x == 0;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        int sp = -1;
        vector <int> y(n, 0);
        vector<vector<int>> v(n, vector<int>(m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> v[i][j];
            }
        }
        for(int i = 0; i < n; i++) {
            vector <int> a = v[i];
            vector <int> b = v[(i + 1) % n];
            if(can_swap(a, b)) {
                y[i]++;
                y[(i + 1) % n]++;
            }
        }
        for(int i = 0; i < n; i++) {
            // cout << y[i] << " ";
            if(y[i] == 0) sp = i;
        }
        cout << sp + 1 << " " << ans << '\n';
    }
    
    return 0;
}