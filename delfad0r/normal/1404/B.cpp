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
    int N, a, b, da, db;
    cin >> N >> a  >> b >> da >> db;
    --a;
    --b;
    vector<vector<int>> G(N);
    for(int n = 1; n < N; ++n) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    if(db <= 2 * da) {
        cout << "Alice\n";
        return;
    }
    vector<int> d(N);
    function<void(int, int)> dfs = [&](int n, int p) {
        for(auto x : G[n]) {
            if(x != p) {
                d[x] = d[n] + 1;
                dfs(x, n);
            }
        }
    };
    d[a] = 0;
    dfs(a, -1);
    if(d[b] <= da) {
        cout << "Alice\n";
        return;
    }
    int v = int(max_element(all_of(d)) - d.begin());
    d[v] = 0;
    dfs(v, -1);
    int diam = *max_element(all_of(d));
    if(diam <= 2 * da) {
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
    }
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