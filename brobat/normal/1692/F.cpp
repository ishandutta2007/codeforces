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
        vector <int> v(10, 0);
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            v[x % 10]++;
        }
        bool pos = false;
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                for(int k = 0; k < 10; k++) {
                    if((i + j + k) % 10 == 3) {
                        v[i]--;
                        v[j]--;
                        v[k]--;
                        if(v[i] >= 0 && v[j] >= 0 && v[k] >= 0) pos = true;
                        v[i]++;
                        v[j]++;
                        v[k]++;
                    }
                }
            }
        }
        cout << (pos ? "YES" : "NO") << '\n';
    }
    
    return 0;
}