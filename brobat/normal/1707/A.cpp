#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n, q;
        cin >> n >> q;
        vector <int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        if(q >= n) {
            for(int i = 0; i < n; i++) cout << 1;
            cout << '\n';
        } else {
            int curr = 0;
            deque<int> ans;
            for(int i = n - 1; i >= 0; i--) {
                if(curr < v[i]) {
                    if(curr == q) {
                        ans.push_front(0);
                    } else {
                        curr++;
                        ans.push_front(1);
                    }
                } else {
                    ans.push_front(1);
                }
            }
            for(auto i : ans) cout << i;
            cout << '\n';
        }
    }
    
    return 0;
}