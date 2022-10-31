#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int> > vvi;

int n;
vvi G;
const int N = 100005;
int cur[N],goal[N];

vector<int> chosen,w;

void dfs(int v, int f, int p) {
    int a = 0;
    if((cur[v]^w[p]) != goal[v]) {
        a = 1;
        chosen.push_back(v);
    }
    w[p]^=a;
    for(int i = 0; i < G[v].size(); ++i) {
        int u = G[v][i];
        if(u == f) continue;
        dfs(u,v,1-p);
    }
    w[p]^=a;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    G = vvi(n,vector<int>());
    for(int i = 1; i < n; ++i) {
        int u,v;
        cin >> u >> v;
        G[--u].push_back(--v);
        G[v].push_back(u);
    }
    for(int i = 0; i < n; ++i)
        cin >> cur[i];
    for(int i = 0; i < n; ++i)
        cin >> goal[i];
    w.push_back(0);
    w.push_back(0);
    dfs(0,-1,0);
    cout << chosen.size() << "\n";
    for(int i = 0; i < chosen.size(); ++i) {
        cout << chosen[i]+1 << "\n";
    }
}