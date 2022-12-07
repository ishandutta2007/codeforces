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
        vector <int> a(n), b(n), c(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> b[i];
            c[i] = a[i] - b[i];
        }
        int sum = accumulate(c.begin(), c.end(), 0ll);

        vector<vector<int>> l(n);
        vector<vector<int>> r(n);
        vector<int> cnt(m, 0);
        vector<pair<int, int>> seg(m);
        for(int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            --a; --b;
            l[a].push_back(i);
            r[b].push_back(i);
            seg[i] = {a, b};
        }

        if(sum != 0) {
            cout << "NO\n";
            continue;
        }
        
        set <int> x;
        set <int> y;
        int ts = 0;
        for(int i = 0; i < n; i++) {
            if(ts == 0) {
                x.insert(i);
            }
            ts += c[i];
            if(ts == 0) {
                y.insert(i);
            }
        }
        set <int> lx, ly; // LEFT values.
        for(int i = 0; i < n; i++) {
            if(x.find(i) == x.end()) lx.insert(i);
            if(y.find(i) == y.end()) ly.insert(i);
        }
        lx.insert(n);
        ly.insert(n);

        for(int i = 0; i < n; i++) {
            if(x.find(i) != x.end()) {
                for(auto j : l[i]) {
                    cnt[j]++;
                }
                l[i].clear();
            }
            if(y.find(i) != y.end()) {
                for(auto j : r[i]) {
                    cnt[j]++;
                }
                r[i].clear();
            }
        }
        queue <int> q;
        for(int i = 0; i < m; i++) {
            if(cnt[i] == 2) {
                q.push(i);
            }
        }
        bool pos; // TRUE--> YES. FALSE--> NO.
        while(true) {
            if((int)x.size() == n) {
                pos = true;
                break;
            }
            if(q.empty()) {
                pos = false;
                break;
            }
            int ind = q.front();
            q.pop();
            int tl = seg[ind].first;
            int tr = seg[ind].second;
            vector <int> lv, rv; // which lv and rv need to be inserted now.
            while(true) {
                auto t = lx.lower_bound(tl);
                if((*t) > tr) break;
                lv.push_back(*t);
                x.insert(*t);
                lx.erase(t);
            }
            while(true) {
                auto t = ly.lower_bound(tl);
                if((*t) > tr) break;
                rv.push_back(*t);
                y.insert(*t);
                ly.erase(t);
            }
            for(auto i : lv) {
                for(auto j : l[i]) {
                    cnt[j]++;
                    if(cnt[j] == 2) {
                        q.push(j);
                    }
                }
                l[i].clear();
            }
            for(auto i : rv) {
                for(auto j : r[i]) {
                    cnt[j]++;
                    if(cnt[j] == 2) {
                        q.push(j);
                    }
                }
                r[i].clear();
            }
        }
        cout << (pos ? "YES" : "NO") << '\n';
    }
    
    return 0;
}