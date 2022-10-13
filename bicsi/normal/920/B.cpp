#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;    

        vector<pair<int, int>> V(n);
        vector<int> starts[5005], ends[5005];

        for (int i = 0; i < n; ++i) {
            cin >> V[i].first >> V[i].second;
            starts[V[i].first].push_back(i);
            ends[V[i].second].push_back(i);
        }
        
        deque<int> q;
        vector<int> OK(n, 0);

        for (int t = 1; t <= 5000; ++t) {
            for (auto x : starts[t]) {
                q.push_back(x);    
            }
            if (q.size()) {
                OK[q.front()] = t;
                q.pop_front();
            }
            for (auto x : ends[t]) {
                auto it = find(q.begin(), q.end(), x);
                if (it != q.end()) q.erase(it);
            }
        }

        for (auto x : OK) cout << x << " "; cout << '\n';
    }


    return 0;
}