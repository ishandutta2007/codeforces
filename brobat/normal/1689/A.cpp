#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        multiset<char> a, b;
        for(int i = 0; i < n; i++) {
            char c; cin >> c; a.insert(c);
        }
        for(int i = 0; i < m; i++) {
            char c; cin >> c; b.insert(c);
        }
        int curr = -1; // 0 for a, 1 for b
        int done = 0;
        string ans;
        for(int i = 0; i < n + m; i++) {
            if(a.empty() || b.empty()) break;
            auto c = a.begin();
            auto d = b.begin();
            if((*c) < (*d)) {
                if(curr == 0) {
                    if(done == k) {
                        ans += (*d);
                        curr = 1;
                        done = 1;
                        b.erase(d);
                    } else {
                        ans += (*c);
                        a.erase(c);
                        done++;
                    }
                } else {
                    curr = 0;
                    done = 1;
                    ans += (*c);
                    a.erase(c);
                }
            } else {
                if(curr == 1) {
                    if(done == k) {
                        ans += (*c);
                        curr = 0;
                        done = 1;
                        a.erase(c);
                    } else {
                        ans += (*d);
                        b.erase(d);
                        done++;
                    }
                } else {
                    curr = 1;
                    done = 1;
                    ans += (*d);
                    b.erase(d);
                }
            }
        }
        cout << ans << '\n';
    }
    
    return 0;
}