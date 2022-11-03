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

vector<int> G[100100];
int N, K;
bool visited[100100];

int dfs(int n) {
    visited[n] = true;
    int ans = 1;
    for(int x : G[n]) {
        if(not visited[x]) {
            ans += dfs(x);
        }
    }
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> K;
    for(int k = 0; k < K; ++k) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    for(int n = 0; n < N; ++n) {
        if(not visited[n]) {
            K -= dfs(n) - 1;
        }
    }
    cout << K << "\n";
    
    return 0;
}