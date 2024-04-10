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
        map <int, int> p; // previous index
        map <int, int> l; // local max
        map <int, int> g; // global max
        map <int, int> e; // ending index of global max
        for(int i = 0; i < n; i++) {
            if(p.find(v[i]) == p.end()) {
                l[v[i]] = g[v[i]] = 1;
                p[v[i]] = i;
                e[v[i]] = i;
                continue;
            }
            int prev = p[v[i]];
            int sub = i - prev - 1; 
            l[v[i]] = max(1ll, l[v[i]] - sub + 1);
            if(l[v[i]] > g[v[i]]) {
                e[v[i]] = i;
                g[v[i]] = l[v[i]];
            }
            p[v[i]] = i;
        }
        int val = 0;
        int ans = 0;
        int end = 0;
        for(int i = 0; i < n; i++) {
            if(g[v[i]] > val) {
                val = g[v[i]];
                ans = v[i];
                end = e[v[i]];
            }
        }
        
        int start = end;
        int curr = 1;
        int mx_curr = 1;
        for(int i = end - 1; i >= 0; i--) {
            if(v[i] != v[end]) {
                curr--;
            } else {
                curr++;
            }
            if(curr > mx_curr) {
                start = i;
                mx_curr = curr;
            }
        }
        cout << ans << " " << start + 1 << " " << end + 1 << '\n';
    }
    
    return 0;
}