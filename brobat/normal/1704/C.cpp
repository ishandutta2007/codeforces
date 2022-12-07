#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector <int> v(m);
        for(int i = 0; i < m; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        priority_queue <int> pq;
        for(int i = 1; i < m; i++) {
            pq.push(v[i] - v[i - 1] - 1);
        }
        pq.push(n - v[m - 1] + v[0] - 1);
        int day = 0;
        int ans = m;
        while(!pq.empty()) {
            int curr = pq.top();
            pq.pop();
            int gap_left = curr - 2*day;
            if(gap_left <= 0) {
                ans += curr;
                continue;
            }
            ans += curr - gap_left;
            if(gap_left == 1) {
                day++;
                continue;
            }
            if(gap_left == 2) {
                ans++;
                day++;
                continue;
            }
            day += 2;
            ans++;
        }
        cout << ans << '\n';
    }
    
    return 0;
}