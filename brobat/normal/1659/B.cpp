#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector <int> ans(n, 0);
        if(k % 2 == 1) {
            int d = 0;
            for(int i = 0; i < n; i++) {
                if(d == k) break;
                if(s[i] == '1') {
                    ans[i] = 1;
                    d++;
                }
            }
            int ez = (k - d)/2;
            int hard = (k - d) % 2;
            ans[0] += (2*ez);
            ans[n - 1] += hard;
            for(int i = 0; i < n; i++) {
                if(s[i] == '1') {
                    if(ans[i] % 2 == 1) cout << 1;
                    else cout << 0;
                } else {
                    if(ans[i] % 2 == 1) cout << 0;
                    else cout << 1;
                }
            }
            cout << '\n';
            for(int i = 0; i < n; i++) {
                cout << ans[i] << " ";
            }
            cout << '\n';
        } else {
            int d = 0;
            for(int i = 0; i < n; i++) {
                if(d == k) break;
                if(s[i] == '0') {
                    ans[i] = 1;
                    d++;
                }
            }
            int ez = (k - d)/2;
            int hard = (k - d) % 2;
            ans[0] += (2*ez);
            ans[n - 1] += hard;
            for(int i = 0; i < n; i++) {
                if(s[i] == '0') {
                    if(ans[i] % 2 == 1) cout << 1;
                    else cout << 0;
                } else {
                    if(ans[i] % 2 == 1) cout << 0;
                    else cout << 1;
                }
            }
            cout << '\n';
            for(int i = 0; i < n; i++) {
                cout << ans[i] << " ";
            }
            cout << '\n';
        }
    }
    
    return 0;
}