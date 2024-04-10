#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector <int> v(k);
        for(int i = 0; i < k; i++) {
            cin >> v[i];
            v[i] = k - v[i] + 1;
        }
        int x = n*m - 2;
        set <int> storage;
        int done = 0;
        bool pos = true;
        int started = 0;
        // cout << x << '\n';
        while(done < k) {
            if(storage.find(done + 1) == storage.end()) {
                // Put next value from v in storage
                if((int)storage.size() >= x - 1) {
                    pos = false;
                    break;
                } else if(started < k) {
                    storage.insert(v[started]);
                    // cout << v[started] << " transferred into storage.\n";
                    started++;
                } else assert(false);
            } else {
                // Transfer from storage to (n, m).
                if((int)storage.size() >= x) {
                    pos = false;
                    break;
                } else {
                    // cout << done + 1 << " transferred to (n, m).\n";
                    storage.erase(done + 1);
                    done++;
                }
            }
        }
        cout << (pos ? "YA" : "TIDAK") << '\n';
    }
    
    return 0;
}