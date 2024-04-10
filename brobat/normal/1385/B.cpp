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
        map <int, bool> done;
        for(int i = 0; i < 2*n; i++) {
            int x;
            cin >> x;
            if(done[x]) continue;
            cout << x << " ";
            done[x] = true;
        }
        cout << '\n';
    }
    
    return 0;
}