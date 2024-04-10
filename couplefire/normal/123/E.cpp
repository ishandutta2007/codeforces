#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005

long double dp1[MAXN] = {0};
int numEdge[MAXN] = {0};
long double dp2[MAXN];
int depth[MAXN];
int pEntrance[MAXN];
int pEnd[MAXN];
int n;
long double sumEntrance = 0, sumEnd = 0;
vector<int> adj[MAXN];

void dfs1(int v = 0, int p = 0, int d = 0){
    depth[v] = d;
    for(auto u : adj[v]){
        if(u == p) continue;
        dfs1(u, v, d+1);
        numEdge[v] += numEdge[u]+1;
        dp1[v] += dp1[u];
    }
    dp1[v] += (n-1-numEdge[v])*(pEnd[v]/sumEnd);
}

void dfs2(int v = 0, int p = 0){
    for(auto u : adj[v]){
        if(u == p) continue;
        dp2[u] = dp2[v];
        dp2[u] -= (n-1-numEdge[u])*(pEnd[u]/sumEnd);
        dp2[u] += (numEdge[u]+1)*(pEnd[v]/sumEnd);
        dfs2(u, v);
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(12);
    cin >> n;
    for(int i = 0; i<n-1; i++){
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 0; i<n; i++){
        cin >> pEntrance[i] >> pEnd[i];
        sumEntrance += pEntrance[i];
        sumEnd += pEnd[i];
    }
    dfs1();
    dp2[0] = dp1[0];
    dfs2();
    long double ans = 0;
    for(int i = 0; i<n; i++){
        ans += (dp2[i])*pEntrance[i]/sumEntrance;
    }
    cout << ans << endl;
}