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
        vector <int> w(n);
        for(int i = 0; i < n; i += 2) {
            w[i] = v[i/2];
        }
        for(int i = 1; i < n; i += 2) {
            w[i] = v[(n + 1)/2 + i/2];
        }
        bool pos = true;
        for(int i = 0; i < n; i++) {
            int a = w[(i + 1) % n];
            int b = w[(i - 1 + n) % n];
            if((w[i] > a) && (w[i] > b)) continue;
            if((w[i] < a) && (w[i] < b)) continue;
            pos = false;
        }
        if(!pos) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for(int i = 0; i < n; i++) {
            cout << w[i] << " ";
        }
        cout << '\n';
    }
    
    return 0;
}