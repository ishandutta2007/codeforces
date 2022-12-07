#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n >> x;
        vector <int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        // insert 1 and insert x.
        int mn = v[0] - 1;
        int mn_ind = 0; // index at WHICH to insert. 
        if(v[n - 1] < v[0]) {
            mn = v[n - 1] - 1;
            mn_ind = n;
        }
        for(int i = 1; i < n; i++) {
            // answer if we inserted AT i.
            int ch = (abs(v[i] - 1) + abs(v[i - 1] - 1)) - abs(v[i] - v[i - 1]);
            if(ch < mn) {
                mn = ch;
                mn_ind = i;
            }
        }
        // insert 1 at i.
        v.insert(v.begin() + mn_ind, 1);
        // for(auto i : v) cout << i << " ";
        // cout << '\n';
        n++;
        mn = abs(v[0] - x);
        mn_ind = 0;
        if(abs(v[n - 1] - x) < mn) {
            mn = abs(v[n - 1] - x);
            mn_ind = n;
        }
        for(int i = 1; i < n; i++) {
            // answer if we inserted AT i.
            int ch = (abs(v[i] - x) + abs(v[i - 1] - x)) - abs(v[i] - v[i - 1]);
            if(ch < mn) {
                mn = ch;
                mn_ind = i;
            }
        }
        n++;
        v.insert(v.begin() + mn_ind, x);
        // for(auto i : v) cout << i << " ";
        // cout << '\n';
        int ans = 0;
        for(int i = 1; i < n; i++) {
            ans += abs(v[i] - v[i - 1]);
        }
        cout << ans << '\n';
    }
    
    return 0;
}