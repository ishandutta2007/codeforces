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
    int N, M;
    cin >> N >> M;
    vector<int> A(N, -1), B(N, -1);
    vector<vector<int>> G(N);
    for(int m = 0; m < M; ++m) {
        int x, y;
        cin >> x >> y;
        A[x - 1] = B[y - 1] = m;
    }
    for(int n = 0; n < N; ++n) {
        if(A[n] >= 0 and B[n] >= 0) {
            G[A[n]].push_back(B[n]);
        }
    }
    vector<bool> visited(N, false), cycle(N, false);
    function<void(int, int)> dfs = [&](int n, int p) {
        if(p == n and visited[n]) {
            cycle[n] = true;
        }
        if(visited[n]) {
            return;
        }
        visited[n] = true;
        for(auto x : G[n]) {
            dfs(x, p);
        }
    };
    for(int n = 0; n < N; ++n) {
        if(not visited[n]) {
            dfs(n, n);
        }
    }
    int ans = M;
    for(int n = 0; n < N; ++n) {
        if(A[n] == B[n] and A[n] != -1) {
            ans -= 2;
        }
        if(cycle[n]) {
            ++ans;
        }
    }
    //~ debug(G);
    //~ debug(cycle);
    cout << ans << "\n";
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