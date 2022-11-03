#include "bits/stdc++.h"

#define all_of(x) std::begin(x), std::end(x)
#ifdef _GLIBCXX_DEBUG
    #define debug(x) cerr << #x << ": " << x << endl
#else
    #define debug(x) 
#endif

using namespace std;

using LL = long long;

template<typename T>
ostream& operator << (ostream& out, const vector<T>& v) {
    out << "[";
    for(const auto& x : v) {
        out << x << ", ";
    }
    return out << "]";
}
template<typename T>
istream& operator >> (istream& in, vector<T>& v) {
    for(auto& x : v) {
        in >> x;
    }
    return in;
}

template<typename S, typename T>
ostream& operator << (ostream& out, const pair<S, T>& p) {
    return out << "{" << p.first << ", " << p.second << "}";
}

void solve() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<int>> G(N);
    vector<int> deg(N, 0);
    vector<bool> deleted(N, false);
    while(M--) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        G[x].push_back(y);
        G[y].push_back(x);
        ++deg[x];
        ++deg[y];
    }
    priority_queue<pair<int, int>> Q;
    for(int n = 0; n < N; ++n) {
        Q.emplace(-deg[n], n);
        sort(all_of(G[n]));
    }
    while(Q.size()) {
        auto [d, n] = Q.top();
        Q.pop();
        d = -d;
        if(deleted[n] or d != deg[n]) {
            continue;
        }
        if(d < K - 1) {
            deleted[n] = true;
            for(auto x : G[n]) {
                if(not deleted[x]) {
                    --deg[x];
                    Q.emplace(-deg[x], x);
                }
            }
            continue;
        }
        if(d >= K) {
            vector<int> ans;
            for(int i = 0; i < N; ++i) {
                if(not deleted[i]) {
                    assert(deg[i] >= K);
                    ans.push_back(i);
                }
            }
            cout << 1 << " " << ans.size() << "\n";
            for(int i : ans) {
                cout << i + 1 << " ";
            }
            cout << "\n";
            return;
        }
        bool ok = true;
        vector<int> g;
        for(int x : G[n]) {
            if(not deleted[x]) {
                g.push_back(x);
            }
        }
        for(int i = 0; ok and i < int(g.size()); ++i) {
            for(int j = i + 1; j < int(g.size()); ++j) {
                if(not binary_search(all_of(G[g[j]]), g[i])) {
                    ok = false;
                    break;
                }
            }
        }
        /*for(auto it = G[n].begin(); ok and it != G[n].end(); ++it) {
            int x = *it;
            for(auto is = next(it); is != G[n].end(); ++is) {
                int y = *is;
                if(G[x].count(y) == 0) {
                    ok = false;
                    break;
                }
            }
        }*/
        if(ok) {
            cout << 2 << "\n" << n + 1 << " ";
            for(int i : G[n]) {
                if(not deleted[i]) {
                    cout << i + 1 << " ";
                }
            }
            cout << "\n";
            return;
        } else {
            deleted[n] = true;
            for(auto x : G[n]) {
                if(not deleted[x]) {
                    --deg[x];
                    //~ G[x].erase(n);
                    Q.emplace(-deg[x], x);
                }
            }
        }
    }
    cout << "-1\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    
    return 0;
}