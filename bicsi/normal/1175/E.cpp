#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<pair<int, int>> segs;
    for (int i = 0; i < n; ++i) {
        int l, r; cin >> l >> r;
        segs.emplace_back(r, -l);
    }

    sort(segs.begin(), segs.end());

    vector<pair<int, int>> stk;
    for (int i = 0; i < n; ++i) {
        int l, r; tie(r, l) = segs[i]; l = -l;
        while (stk.size()) {
            if (stk.back().first >= l)
                stk.pop_back();
            else break;
        }
        stk.emplace_back(l, r);
    }
    segs = stk;
    n = segs.size();
    
    //for (auto x : segs) 
    //    cerr << "I: " << x.first << " " << x.second << '\n';    
    
    vector<pair<int, int>> merged;
    for (int i = 0; i < n; ++i) {
        int l, r; tie(l, r) = segs[i];
        if (merged.size() && merged.back().second >= l)
            merged.back().second = r;
        else merged.emplace_back(l, r);
    }
    
    //for (auto x : merged) 
    //    cerr << "M: " << x.first << " " << x.second << '\n';    

    auto by_l = [&](pair<int, int> a, pair<int, int> b) {
        return a.first < b.first;
    };
    auto by_r = [&](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    };

    vector<vector<int>> nxt(20, vector<int>(n));
    int j = 0;
    for (int i = 0; i < n; ++i) {
        while (j < n && segs[j].first <= segs[i].second)
            ++j;
        j = max(i + 1, j - 1);
        nxt[0][i] = j; 
    }

    for (int i = 1; i < 20; ++i) {
        for (int j = 0; j < n; ++j) {
            int go = nxt[i - 1][j];
            if (go < n) {
                nxt[i][j] = nxt[i - 1][go];
            } else {
                nxt[i][j] = n;
            }
        }
    }
    /*
    for (int i = 0; i < n; ++i) {
        cerr << i << ": [" << segs[i].first << " " << segs[i].second << "] ";
        cerr << "goes to: " << nxt[0][i] << endl;
    }
    */
    
    for (int i = 0; i < m; ++i) {
        int x, y; cin >> x >> y;
        auto it = upper_bound(merged.begin(), merged.end(), make_pair(x, y), by_l);
        if (it == merged.begin() || prev(it)->second < y) {
            cout << -1 << '\n';
        } else {
            int ans = 1;
            auto it1 = upper_bound(segs.begin(), segs.end(), make_pair(x, y), by_l);
            assert(it1 != segs.begin());
            int pos = it1 - segs.begin() - 1;
            if (segs[pos].second >= y) {
                cout << 1 << '\n';
                continue;
            }

            for (int step = 19; step >= 0; --step) {
                int go = nxt[step][pos];
                if (go == n || segs[go].second >= y)
                    continue;
                pos = go;
                ans += (1 << step);
            }
            cout << ans + 1 << '\n';
        }
    }

    return 0;
}