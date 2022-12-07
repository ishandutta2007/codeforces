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
        vector <int> ca(n), cb(n);
        vector <int> nx(n);
        map <int, int> m;
        for(int i = 0; i < n; i++) {
            cin >> ca[i];
            --ca[i];
            m[ca[i]] = i;
        }
        for(int i = 0; i < n; i++) {
            cin >> cb[i];
            --cb[i];
            nx[m[cb[i]]] = i;
        }
        vector <int> vis(n, false);
        set <int> done;
        for(int i = 0; i < n; i++) done.insert(i);
        vector <int> ord;
        for(int i = 0; i < n; i++) {
            if(vis[i]) continue;
            deque <int> cycle;
            cycle.push_back(i);
            int curr = nx[i];
            vis[i] = true;
            while(curr != i) {
                cycle.push_back(curr);
                vis[curr] = true;
                curr = nx[curr];
            }
            int x = cycle.size();
            if(x % 2) cycle.pop_front();
            for(auto j : cycle) ord.push_back(j);
        }
        // for(auto i : ord) cout << i + 1 << " ";
        // cout << '\n';
        vector <int> num(n, -1);
        bool first = true;
        for(auto i : ord) {
            int x;
            if(first) {
                x = *done.begin();
                done.erase(done.begin());
            } else {
                x = *(--done.end());
                done.erase((--done.end()));
            }
            first = !first;
            num[i] = x;
        }
        for(int i = 0; i < n; i++) {
            if(num[i] == -1) {
                num[i] = *done.begin();
                done.erase(done.begin());
            }
        }
        // for(int i = 0; i < n; i++) {
        //     cout << num[i] + 1 << " ";
        // }
        // cout << '\n';
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans += abs(num[i] - num[nx[i]]);
        }
        cout << ans << '\n';
    }
    
    return 0;
}