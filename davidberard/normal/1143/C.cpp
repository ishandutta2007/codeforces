#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

const int NMAX = 100100;

vector<int> adj[NMAX];
int c[NMAX];
int par[NMAX];
vector<int> rem;

int dfs(int u) {
    int hate = 1;
    for(auto& v : adj[u]) {
        hate &= dfs(v);
    }
    if(hate && c[u] && par[u] != -1) {
        rem.push_back(u);
        return 1;
    }
    return c[u];
}

int n;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    int rt = 0;
    for(int i = 1;i<=n;++i) {
        cin >> par[i] >> c[i];
        if(par[i] == -1) rt = i;
        else {
            adj[par[i]].push_back(i);
        }
    }
    //cerr << " a " << endl;
    dfs(rt);
    //cerr << " b " << endl;
    sort(rem.begin(), rem.end());
    if(rem.size() == 0) cout << -1 << endl;
    else {
        for(auto& x : rem) cout << x << " ";
        cout << endl;
    }
    return 0;
}