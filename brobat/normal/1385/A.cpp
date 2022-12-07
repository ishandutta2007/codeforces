#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        vector <int> v(3);
        cin >> v[0] >> v[1] >> v[2];
        sort(v.begin(), v.end());
        if(v[1] == v[2] && v[0] <= v[1]) {
            cout << "YES\n";
            cout << v[0] << " " << v[0] << " " << v[1] << '\n';
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}