#include <bits/stdc++.h>

using namespace std;

struct Dancer {
    int idx, x, t;
    
    bool operator<(const Dancer& oth) const {
        if (t != oth.t) return t < oth.t;
        return idx < oth.idx;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    
    int n, w, h; cin >> n >> w >> h;
    
    map<int, vector<Dancer>> dh, dv;
    vector<pair<int, int>> ans(n, {-1, -1});
    
    set<int> all;
    for (int i = 0; i < n; ++i) {
        int v, x, t;
        cin >> v >> x >> t;
        
        if (v == 1)
            dv[x - t].push_back(Dancer{i, x, t});
        else
            dh[x - t].push_back(Dancer{i, x, t});
    
        all.insert(x - t);
        
    }
    
    auto DoMagic = [&ans, &h, &w](vector<Dancer> dv, vector<Dancer> dh) {
        
        sort(dv.begin(), dv.end(), [](Dancer a, Dancer b) { return a.t < b.t; });
        sort(dh.begin(), dh.end(), [](Dancer a, Dancer b) { return a.x < b.x; });
        
        vector<pair<int, int>> endpoints;
        for (auto d : dv) endpoints.emplace_back(d.x, h);
        for (auto d : dh) endpoints.emplace_back(w, -d.x);
        
        sort(endpoints.begin(), endpoints.end());
        
        vector<pair<int, int>> dancs;
        for (auto d : dv) dancs.emplace_back(d.x, d.idx);
        for (auto d : dh) dancs.emplace_back(-d.x, d.idx);
        
        sort(dancs.begin(), dancs.end());
        for (int i = 0; i < dancs.size(); ++i) {
            ans[dancs[i].second] = endpoints[i];
        }
    };
    
    for (auto x : all) {
        DoMagic(dv[x], dh[x]);
    }
    
    
    
    for (auto p : ans)
        cout << p.first << " " << abs(p.second) << "\n";
    
    return 0;
}