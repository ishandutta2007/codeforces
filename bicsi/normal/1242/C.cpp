#include <bits/stdc++.h>
#define int long long 

using namespace std;
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    vector<vector<int>> have(n);
    vector<int> total(n, 0);
    int need = 0;
    map<int, int> revmap;
 
    for (int i = 0; i < n; ++i) {
        int k; cin >> k;
        while (k--) {
            int x; cin >> x;
            total[i] += x;
            need += x;
            have[i].push_back(x);
            revmap[x] = i;
        }
    }
 
    if (need % n) {
        cout << "No\n";
        return 0;
    }
 
    vector<vector<pair<int, int>>> sol(1 << n);
 
    need /= n;
    for (int i = 0; i < n; ++i) {
        for (auto x : have[i]) {
            int rem = need - total[i] + x;
            int at = i;
 
            bool ok = true;
            int msk = (1 << i);
 
            vector<pair<int, int>> ops(n, make_pair(-1, -1));
            while (true) {
                auto it = revmap.find(rem);
                if (it == revmap.end()) {
                    ok = false;
                    break;
                }
 
                int nat = it->second;
                ops[nat] = make_pair(at, rem);
                if (rem == x) break;
                
                if (msk & (1 << nat)) {
                    ok = false;
                    break;
                }
                msk |= (1 << nat);
                at = nat;
                rem = need - total[nat] + rem;
            }
 
            if (ok) 
                sol[msk] = ops;
        }
    }
    for (int m = 1; m < (1 << n); ++m) if (sol[m].empty()) {
        for (int m1 = ((m - 1) & m); m1 > 0; m1 = ((m1 - 1) & m)) {
            int m2 = m ^ m1;
            if (sol[m1].size() && sol[m2].size()) {
                vector<pair<int, int>> ret(n);
                for (int i = 0; i < n; ++i)
                    ret[i] = max(sol[m1][i], sol[m2][i]);
                sol[m1 | m2] = ret;
                break;
            }
        }
    }
 
    if (sol[(1 << n) - 1].empty()) {
        cout << "No\n";
        return 0;    
    }
 
    cout << "Yes\n";
    for (int i = 0; i < n; ++i)
        cout << sol[(1 << n) - 1][i].second << " " 
            << sol[(1 << n) - 1][i].first + 1 << '\n';
 
    return 0;
}