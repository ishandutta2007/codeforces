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
        int cnt = 0;
        int i = 1;
        while(i < n) {
            if(v[i] < v[i - 1]) {
                cnt++;
                i++;
            }
            i++;
        }
        cout << cnt << '\n';
    }
    
    return 0;
}