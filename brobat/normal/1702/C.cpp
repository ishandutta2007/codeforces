#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        map<int, pair<int, int>> m;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if(m.find(x) == m.end()) {
                m[x] = {i, i};
            } else {
                m[x].second = i;
            }
        }
        for(int i = 0; i < k; i++) {
            int a, b;
            cin >> a >> b;
            if(m.find(a) == m.end() || m.find(b) == m.end()) cout << "NO";
            else if(m[a].first <= m[b].second) cout << "YES";
            else cout << "NO";
            cout << '\n';
        }
    }
    
    return 0;
}