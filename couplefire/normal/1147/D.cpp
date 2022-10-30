#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353

struct Graph{
    vector<vector<int>> adj;
    vector<int> val;
    int n;
    string s;

    Graph(){}
    Graph(int n_){n=n_;adj.resize(n);val.assign(n, -1);}

    void ae(int a, int b){
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int getVal(int i){return s[i]-'0';}

    bool dfs(int v, int cur){
        if(val[v] != -1 && val[v] != cur) return false;
        if(val[v] != -1) return true;
        val[v] = cur;
        for(auto u : adj[v]){
            int vv;
            if(v < s.size() && u >= s.size()) vv = (cur^getVal(v));
            if(u < s.size() && v >= s.size()) vv = (cur^getVal(u));
            if(v < s.size() && u < s.size()) vv = cur;
            if(v >= s.size() && u >= s.size()) vv = cur;
            if(!dfs(u, vv)) return false;
        }
        return true;
    }
};

string s;
int n;
int ans = 0;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    n = s.size();
    reverse(s.begin(), s.end());
    for(int i = 0; i<n-1; i++){
        Graph G(n+i+1);
        G.s = s;
        for(int j = 0; j<((i+1)/2); j++){
            G.ae(j+n, i-j+n);
        }
        for(int j = 0; j<=i; j++){
            if(s[j] == '1' || s[j] == '0') G.ae(j, j+n);
        }
        for(int j = 0; j<((n)/2); j++) G.ae(j, n-1-j);
        int curans = 1;
        if(G.dfs(n, 1)) curans *= 1;
        else curans *= 0;
        for(int j = i+1; j<n; j++){
            if(s[j] == '?') continue;
            if(G.dfs(j, s[j]-'0')) curans *= 1;
            else curans *= 0;
        }
        for(int j = 0; j<(n+i+1); j++){
            if(G.val[j] == -1){
                if(G.dfs(j, 1)) curans *= 2;
                else curans *= 0;
                if(curans >= MOD) curans -= MOD;
            }
        }
        ans += curans;
        if(ans >= MOD) ans -= MOD;
    }
    cout << ans << endl;
}