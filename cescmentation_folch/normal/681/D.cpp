#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef set<int> si;
typedef pair<int, int> pi;

const int MAX = 100010;
int T[MAX];
int A[MAX];
vi G[MAX];
vi tet;
bool xec = true;

void dfs(int x) {
    for (int i = 0; i < G[x].size(); ++i) dfs(G[x][i]);
    for (int i = 0; i < G[x].size(); ++i) {
        int y = G[x][i];
        if (A[y] != -1 and A[y] != A[x]) xec = false;
    }
    if (A[x] == x) {
        tet.push_back(x);
        A[x] = -1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
         int x,y;
         cin >> x >> y;
         G[x].push_back(y);
         ++T[y];
    }
    for (int i = 1; i <= n; ++i) cin >> A[i];
    for (int i = 1; i <= n; ++i) {
        if (T[i] == 0) dfs(i);
    }
    if (xec) {
        cout << tet.size() << endl;
        for (int i = 0; i < tet.size(); ++i) cout << tet[i] << endl;
    }
    else cout << -1 << endl;
}