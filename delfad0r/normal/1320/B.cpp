#include <bits/stdc++.h>

using namespace std;

typedef long long LL;


template<typename T>
ostream& operator << (ostream& out, const vector<T>& v) {
    out << "[";
    for(const auto& x : v) {
        out << x << ", ";
    }
    return out << "]";
}

template<typename T, typename S>
ostream& operator << (ostream& out, const pair<T, S>& p) {
    return out << "{" << p.first << ", " << p.second << "}";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N), GT(N);
    while(M--) {
        int u, v;
        cin >> u >> v;
        G[u - 1].push_back(v - 1);
        GT[v - 1].push_back(u - 1);
    }
    int K;
    cin >> K;
    vector<int> P(K);
    for(auto& p : P) {
        cin >> p;
        --p;
    }
    vector<int> D(N, -1);
    D[P[K - 1]] = 0;
    deque<int> Q = {P[K - 1]};
    while(Q.size()) {
        int n = Q.front();
        Q.pop_front();
        for(auto x : GT[n]) {
            if(D[x] == -1) {
                D[x] = D[n] + 1;
                Q.push_back(x);
            }
        }
    }
    
    int ans1 = 0, ans2 = 0;
    for(int k = 0; k + 1 < K; ++k) {
        if(D[P[k + 1]] >= D[P[k]]) {
            ans1++;
            ans2++;
        } else {
            for(auto x : G[P[k]]) {
                if(x != P[k + 1] and D[x] + 1 == D[P[k]]) {
                    ans2++;
                    break;
                }
            }
        }
    }
    
    cout << ans1 << " " << ans2 << "\n";
    
    return 0;
}