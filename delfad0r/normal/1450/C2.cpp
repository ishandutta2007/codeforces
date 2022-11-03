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
    int N;
    cin >> N;
    vector<string> G(N);
    for(auto& s : G) {
        cin >> s;
    }
    int K = N * N;
    vector<int> X(3, 0), O(3, 0);
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            if(G[i][j] == 'X') {
                ++X[(i + j) % 3];
            }
            if(G[i][j] == 'O') {
                ++O[(i + j) % 3];
            }
            if(G[i][j] == '.') {
                --K;
            }
        }
    }
    for(int u = 0; u < 3; ++u) {
        int v = (u + 1) % 3;
        if(X[u] + O[v] > K / 3) {
            continue;
        }
        int cnt = 0;
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                if(G[i][j] == 'X' and (i + j) % 3 == u) {
                    G[i][j] = 'O';
                    ++cnt;
                } else if(G[i][j] == 'O' and (i + j) % 3 == v) {
                    G[i][j] = 'X';
                    ++cnt;
                }
            }
        }
        debug(cnt);
        debug(K);
        assert(cnt <= K / 3);
        for(auto& s : G) {
            cout << s << "\n";
        }
        return;
    }
    abort();
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