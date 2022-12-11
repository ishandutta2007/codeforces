#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;

vvi G;
vi F;

int dfs_conta(int x, int p){
    int k = 0;
    for(int i = 0; i < G[x].size(); ++i){
        int y = G[x][i];
        if(y == p) continue;
        k += dfs_conta(y, x);
    }
    if(k == 0 and F[x] == 0) return 0;
    return k + 1;
}

pi dfs1(int x, int p){
    pi k = pi(-1, -1);
    for(int i = 0; i < G[x].size(); ++i){
        int y = G[x][i];
        if(y == p) continue;
        k = max(k, dfs1(y, x));
    }
    if(k == pi(-1, -1)){
        if(F[x] == 0) return k;
        else return pi(1, -x);
    }
    return pi(k.first + 1, k.second);
}

int main(){
    int n, m;
    cin >> n >> m;
    
    G = vvi(n);
    
    for(int i = 0; i < n - 1; ++i){
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    
    F = vi(n, 0);
    
    int ini;
    
    for(int i = 0; i < m; ++i){
        int x;
        cin >> x;
        --x;
        F[x] = 1;
        ini = x;
    }
    
    int lng = 2*(dfs_conta(ini, -1) - 1);
    
    pi tt = dfs1(ini, -1);
    pi tt2 = dfs1(-tt.second, -1);
    
    cout << min(-tt.second, -tt2.second) + 1 << endl;
    cout << lng - tt2.first + 1 << endl;
}