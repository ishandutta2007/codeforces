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
        map<int, int> m; // how many needed.
        vector <int> b(n);
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            while(x % 2 == 0) {
                x /= 2;
            }
            m[x]++;
        }
        for(int i = 0; i < n; i++) {
            cin >> b[i];
        }
        sort(b.begin(), b.end());
        bool pos = true;
        for(auto x : b) {
            // cerr << x << ":";
            bool done = false;
            for(int j = 31; j > 0; j--) {
                if(m.find(x<<j) != m.end() && m[x<<j] > 0) {
                    m[x<<j]--;
                    // cerr << (x<<j);
                    done = true;
                    break;
                }
            }
            int y = x;
            while(y) {
                if(m.find(y) != m.end() && m[y] > 0) {
                    m[y]--;
                    // cerr << y;
                    done = true;
                    break;
                }
                y /= 2;
            }
            pos &= done;
            // cerr << '\n';
        }
        cout << (pos ? "YES" : "NO") << '\n';
    }
    
    return 0;
}