#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector <int> p(n);
        for(int i = 0; i < n; i++) {
            cin >> p[i];
        }
        if(n == 1) {
            cout << 0 << '\n';
            continue;
        }
        function<vector<int>(int, int)> REC = [&](int l, int r) -> vector<int> {
            // returns {number of ops, min, max}. {-1, x, y} if not possible.
            if(r == l + 1) {
                return {p[l] < p[r] ? 0 : 1, min(p[l], p[r]), max(p[l], p[r])};
            }
            int m = (l + r)/2;
            auto a = REC(l, m);
            auto b = REC(m + 1, r);
            if(a.front() == -1 || b.front() == -1) return {-1, -1, -1};
            vector <int> v = {a[1], a[2], b[1], b[2]};
            if(is_sorted(v.begin(), v.end())) {
                return {a.front() + b.front(), a[1], b[2]};
            }
            vector <int> w = {b[1], b[2], a[1], a[2]};
            if(is_sorted(w.begin(), w.end())) {
                return {a.front() + b.front() + 1, b[1], a[2]};
            }
            return {-1, -1, -1};
        };
        cout << REC(0, n - 1).front() << '\n';
    }
    
    return 0;
}