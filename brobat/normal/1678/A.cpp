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
        sort(v.begin(), v.end());
        int cnt = 0;
        bool pos = false;
        if(v[0] == 0) {
            cnt++;
            pos = true;
        }
        for(int i = 1; i < n; i++) {
            if(v[i] == v[i - 1]) pos = true;
            if(v[i] == 0) cnt++;
        }
        cout << (pos ? n - cnt : n - cnt + 1) << '\n';
    }
    
    return 0;
}