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
        if(n == 1) {
            cout << -1 << '\n';
            continue;
        }
        vector <int> p = v;
        // for(int i = 0; i < n; i++) cout << p[i] << " ";
        // cout << '\n';
        for(int i = 0; i < n - 1; i++) {
            // rotate vector (p.begin() + i, p.end()).
            int x = *min_element(p.begin() + i, p.end());
            int x_ind = min_element(p.begin() + i, p.end()) - p.begin();
            int y = n + 1;
            int y_ind = -1;
            for(int j = i; j < n; j++) {
                if(p[j] == x) continue;
                // y = min(y, p[j]);
                if(p[j] < y) {
                    y = p[j];
                    y_ind = j;
                }
            }
            // cout << x << " " << x_ind << " " << y << " " << y_ind << '\n';
            if(x == v[i]) {
                // second min.
                rotate(p.begin() + i, p.begin() + y_ind, p.end());
            } else {
                // min.
                rotate(p.begin() + i, p.begin() + x_ind, p.end());
            }
            // rotate(p.begin() + i, )
            // for(int i = 0; i < n; i++) cout << p[i] << " ";
            // cout << '\n';
        }
        if(p[n - 1] == v[n - 1]) {
            swap(p[n - 1], p[n - 2]);
        }
        for(int i = 0; i < n; i++) {
            cout << p[i] << " ";
        }
        cout << '\n';
    }
    
    return 0;
}