#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> II;


template<typename T>
ostream& operator << (ostream& out, const vector<T>& v) {
    out << "[";
    for(const T& x : v) {
        out << x << ", ";
    }
    return out << "]";
}

template<typename S, typename T>
ostream& operator << (ostream& out, const pair<S, T>& p) {
    return out << "{" << p.first << ", " << p.second << "}";
}

int K;
vector<pair<int, LL>> G[500500];

pair<LL, LL> dfs(int n, int p) {
    LL ansK = 0, ansK1 = 0;
    vector<LL> v;
    for(auto& [x, w] : G[n]) {
        if(x == p) {
            continue;
        }
        auto [s, t] = dfs(x, n);
        //cout << x << pair(s, t) << "\n";
        ansK += s;
        v.push_back(max(0LL, -s + (t + w)));
    }
    if(K <= int(v.size())) {
        nth_element(v.begin(), v.begin() + K - 1, v.end(), greater<LL>());
    }
    ansK += accumulate(v.begin(), v.begin() + min(K, int(v.size())), 0LL);
    ansK1 = ansK;
    if(K <= int(v.size())) {
        ansK1 -= v[K - 1];
    }
    return {ansK, ansK1};
}


void solve() {
    int N;
    cin >> N >> K;
    for(int n = 1; n < N; ++n) {
        int a, b, w;
        cin >> a >> b >> w;
        G[a - 1].emplace_back(b - 1, w);
        G[b - 1].emplace_back(a - 1, w);
    }
    cout << dfs(0, -1).first << "\n";
    for(int n = 0; n < N; ++n) {
        G[n].clear();
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int Q;
    cin >> Q;
    while(Q--) {
        solve();
    }
    
    return 0;
}