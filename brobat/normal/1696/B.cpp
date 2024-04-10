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
        vector <int> z;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if(x == 0) {
                z.push_back(i);
            }
        }
        if((int)z.size() == n) {
            cout << 0 << '\n';
            continue;
        }
        z.push_back(n);
        z.push_back(-1);
        sort(z.begin(), z.end());
        int cnt = 0;
        for(int i = 1; i < (int)z.size(); i++) {
            if(z[i] != z[i - 1] + 1) {
                cnt++;
            }
        }
        if(cnt == 1) cout << 1 << '\n';
        else cout << 2 << '\n';
    }
    
    return 0;
}