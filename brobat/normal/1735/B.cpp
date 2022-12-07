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
        sort(v.begin(), v.end());
        int ans = 0;
        int x = 2*v.front() - 1;
        for(int i = 1; i < n; i++) {
            ans += ceil(v[i]*1.0/x) - 1;
        }
        cout << ans << '\n';
    }
    
    return 0;
}