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
        for(int i = 0; i < n; i++) {
            int b;
            cin >> b;
            int cnt = 0;
            for(int j = 0; j < b; j++) {
                char c;
                cin >> c;
                if(c == 'D') cnt++;
                else cnt--;
            }
            v[i] = (v[i] + cnt + 10) % 10;
        }
        for(auto i : v) cout << i << " ";
        cout << '\n';
    }
    
    return 0;
}