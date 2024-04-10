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
        map<int, int> m;
        for(int i = 0; i < n; i++) {
            int x; cin >> x; m[x]++;
        }
        vector<int> v;
        for(auto i : m) {
            if(i.second >= k) v.push_back(i.first);
        }
        sort(v.begin(), v.end());
        if((int)v.size() == 0) {
            cout << -1 << '\n';
            continue;
        }
        int l = 0;
        int cnt = 1;
        int curr = v[0];
        int ans = 0;
        for(int i = 1; i < (int)v.size(); i++) {
            if(v[i] == v[i - 1] + 1) {
                cnt++;
            } else {
                if(cnt > ans) {
                    ans = cnt;
                    l = curr;
                }
                curr = v[i];
                    cnt = 1;
            }
        }
        if(cnt > ans) {
            ans = cnt;
            l = curr;
        }
        cout << l << " " << l + ans - 1 << '\n';
    }
    
    return 0;
}