#include<bits/stdc++.h>
const int N = 2e5 + 5;
using namespace std;

vector <int> G[N];

vector <int> mv;
stack <int> ms;
int n, sz[N], d[N];

void dfs(int u, int p){
    sz[u] = 1;
    for (auto v : G[u]) if (v != p){
        d[v] = d[u] + 1;
        dfs(v, u);
        sz[u] ^= sz[v];
    }
    mv.push_back(u);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    if (n % 2 == 0) return cout << "NO", 0;
    for (int i = 1; i <= n; i++){
        int p; cin >> p;
        if (p != 0) {
            G[i].push_back(p);
            G[p].push_back(i);
        }
    }
    cout << "YES\n";
    dfs(1, 1);
    sort(mv.begin(), mv.end(), [](int x, int y){
         if (sz[x] != sz[y]) return (sz[x] == 0);
         if (sz[x]) return d[x] < d[y];
         else return d[x] > d[y];
         });
    for (auto v : mv) cout << v << "\n";
}