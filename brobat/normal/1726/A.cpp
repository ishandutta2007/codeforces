#include <bits/stdc++.h>
using namespace std;

int main() {
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
        if(n == 1) {
            cout << 0 << '\n';
            continue;
        }
        int ans = v[n - 1] - v[0];
        ans = max(ans, *max_element(v.begin() + 1, v.end()) - v[0]);
        ans = max(ans, v[n - 1] - *min_element(v.begin(), v.end() - 1));
        for(int i = 0; i < n - 1; i++) {
            ans = max(ans, v[i] - v[i + 1]);
        }
        cout << ans << '\n';
    }
    
    return 0;
}