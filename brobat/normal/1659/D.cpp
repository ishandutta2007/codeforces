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
        int o = 0;
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            o += v[i];
        }
        o /= n; // number of 1s.
        vector <int> ans(n);
        int cnt = 0;
        // cerr << o << '\n';
        deque <int> z; // location of zeros.
        for(int i = 0; i < o; i++) {
            int j = n - 1 - i;
            // cerr << j << " " << v[j] << '\n';
            if(v[j] == n) {
                ans[j] = 1;
                cnt++;
            } else {
                ans[j] = 0;
                z.push_front(j);
            }
        }
        for(int i = n - 1 - o; i >= 0; i--) {
            if(cnt == o) {
                ans[i] = 0;
                continue;
            }
            int left = o - cnt;
            int last_zero_index = z[left - 1];
            int def = last_zero_index - i - 1;
            int x = v[i] - def;
            if(x == i + 1) {
                ans[i] = 1;
                cnt++;
            } else {
                ans[i] = 0;
                z.push_front(i);
            }
            // if(cnt == o) {
            //     ans[i] = 0;
            //     continue;
            // }
            // if(v[i] > i) {
            //     ans[i] = 1;
            //     cnt++;
            //     continue;
            // }
            // if(v[i] == o - cnt) {
            //     ans[i] = 0;
            // } else {
            //     ans[i] = 1;
            //     cnt++;
            // }
        }
        for(int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << '\n';
    }
    
    return 0;
}