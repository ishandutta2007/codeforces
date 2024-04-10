#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector <char> a(n), b(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];
        if(n == 1) {
            if(b[0] == 1) {
                cout << "NO" << '\n';
                continue;
            }
            cout << "YES" << '\n';
            if(a[0] == 0) {
                cout << 0 << '\n';
            } else {
                cout << 1 << '\n';
                cout << 1 << ' ' << 1 << '\n';
            }
            continue;
        }
        bool eq = false;
        bool op = false;
        for(int i = 0; i < n; i++) {
            if(a[i] == b[i]) eq = true;
            else op = true;
        }
        if(eq && op) {
            cout << "NO" << '\n';
            continue;
        }
        vector <pair<int, int>> ans;
        if(op) {
            ans.push_back({0, n - 1});
            for(int i = 0; i < n; i++) {
                if(a[i] == '1') a[i] = '0';
                else a[i] = '1';
            }
        }
        if(a[0] == '1') {
            ans.push_back({1, 1});
            ans.push_back({0, 1});
            a[0] = '0';
            b[0] = '0';
        }
        vector <pair<int, int>> cnt;
        int st = -1;
        for(int i = 0; i < n; i++) {
            if(a[i] == '0') {
                if(st != -1) {
                    cnt.push_back({st, i - 1});
                }
                st = -1;
            } else {
                if(st == -1) st = i;
            }
        }
        if(st != -1) cnt.push_back({st, n - 1});
        for(auto i : cnt) {
            ans.push_back({i.first - 1, i.first - 1});
            ans.push_back({i.first - 1, i.second});
        }
        cout << "YES" << '\n';
        cout << (int)ans.size() << '\n';
        for(auto i : ans) cout << i.first + 1 << ' ' << i.second + 1 << '\n';
    }
    
    return 0;
}