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

unordered_set<int> to_visit;
unordered_set<int> G[100100];

void bfs(int n) {
    vector<int> v;
    for(auto i : to_visit) {
        if(not G[n].count(i)) {
            v.push_back(i);
        }
    }
    for(auto i : v) {
        to_visit.erase(i);
    }
    for(auto i : v) {
        bfs(i);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, M;
    cin >> N >> M;
    for(int n = 0; n < N; ++n) {
        to_visit.insert(n);
    }
    while(M--) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        G[u].insert(v);
        G[v].insert(u);
    }
    int ans = -1;
    for(int n = 0; n < N; ++n) {
        if(to_visit.count(n)) {
            to_visit.erase(n);
            ++ans;
            bfs(n);
        }
    }
    cout << ans << "\n";
    
    
    return 0;
}