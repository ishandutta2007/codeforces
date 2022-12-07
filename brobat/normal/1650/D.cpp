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
        vector <int> ans(n, 0);
        bool pos = true;
        for(int i = n - 1; i >= 0; i--) {
            // Perform shifts from v[0] to v[i] until v[i] becomes i + 1.
            int x = -1;
            for(int j = 0; j <= i; j++) {
                if(v[j] == i + 1) {
                    x = j;
                }
            }
            if(x == -1) {
                pos = false;
                break;
            }
            if(x == i) {
                continue;
            }
            ans[i] = x + 1;
            vector <int> shift(n);
            for(int j = 0; j < n; j++) {
                if(j <= i) {
                    shift[(j + i - x) % (i + 1)] = v[j];
                } else {
                    shift[j] = v[j];
                }
            }
            v = shift;
        }
        for(int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << '\n';
    }
    
    return 0;
}