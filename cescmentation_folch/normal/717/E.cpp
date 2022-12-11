#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

vvi t;
vi c;
vi all_black;

vector<int> s;

void paint(int x, int par){
    s.push_back(x);
    c[x] = -c[x];
    for (int i = 0; i< int(t[x].size()); ++i){
        int v = t[x][i];
        if (v == par) continue;
        paint(v, x);
        s.push_back(x);
        c[x] = -c[x];
        if (c[v] == -1){
            s.push_back(v);
            c[v] = -c[v];
            s.push_back(x);
            c[x] = -c[x];
        }
    }
}

void dfs(int x, int par){
    for (int v : t[x]){
        if (x != par){
            dfs(v, x);
            all_black[x] = all_black[x] and all_black[v];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    c = vi(n);
    t = vvi(n);
    all_black = vi(n, 1);
    for (int i =0; i < n; ++i){
        cin >> c[i];
    }
    for (int i = 0; i < n-1; ++i){
        int u, v;
        cin >> u >> v; --u;--v;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    
    //dfs(0, 0);
    
    
    s.push_back(0);
    for (int i = 0; i< int(t[0].size()-1); ++i){
        int v = t[0][i];
        paint(v, 0);
        s.push_back(0);
        c[0] = -c[0];
        if (c[v] == -1){
            s.push_back(v);
            c[v] = -c[v];
            s.push_back(0);
            c[0] = -c[0];
        }
    }
    
    int v = t[0].back();
    paint(v, 0);
    if (c[v] == -1){
        s.push_back(0);
        c[0] = -c[0];
        s.push_back(v);
        c[v] = -c[v];
        if (c[0] == -1){
            s.push_back(0);
            c[0] = -c[0];
        }
    }
    else if (c[0] == -1) s.push_back(0);
    
    for (int i = 0; i < int(s.size()); ++i){
        if (i) cout << " ";
        cout << s[i]+1;
    }
    cout << endl;
    
}