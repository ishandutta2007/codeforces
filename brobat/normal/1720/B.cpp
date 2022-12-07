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
        vector<int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        cout << v[n - 1] + v[n - 2] - v[0] - v[1] << '\n';
    }
    
    return 0;
}