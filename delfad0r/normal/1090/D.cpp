#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> II;

template<typename T>
ostream& operator << (ostream& out, const vector<T>& v) {
    out << "[";
    for(const T& x : v) {
        out << v << ", ";
    }
    out << "]";
    return out;
}

template<typename T, typename S>
ostream& operator << (ostream& out, const pair<T, S>& p) {
    out << "{" << p.first << ", " << p.second << "}";
    return out;
}

int N, M;
vector<int> G[100100];
bool visited[100100];
int A[100100];
int U = 1;

void dfs(int n, int h) {
    visited[n] = true;
    for(int x : G[n]) {
        if(not visited[x] and x != h) {
            dfs(x, h);
        }
    }
    A[n] = U++;
}

int main() {
    #ifdef DEBUG
    freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M;
    while(M--) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int n = 1; n <= N; ++n) {
        if(int(G[n].size()) == N - 1) {
            continue;
        }
        sort(G[n].begin(), G[n].end());
        for(int h = 1; h <= N; ++h) {
            if(h != n and not binary_search(G[n].begin(), G[n].end(), h)) {
                dfs(n, h);
                ++U;
                for(int i = 1; i <= N; ++i) {
                    if(i != h and not visited[i]) {
                        dfs(i, h);
                    }
                }
                A[h] = A[n] + 1;
                cout << "YES\n";
                for(int i = 1; i <= N; ++i) {
                    cout << A[i] << " ";
                }
                cout << "\n";
                A[h] = A[n];
                for(int i = 1; i <= N; ++i) {
                    cout << A[i] << " ";
                }
                cout << "\n";
                return 0;
            }
        }
    }
    cout << "NO\n";
    return 0;
}