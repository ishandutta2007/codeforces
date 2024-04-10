#include <bits/stdc++.h>
using namespace std;

const int N = 500005;

int n, up[N][20], arr[N], rt;
vector<int> adj[N];
long long ans;

void dfs(int v, int p){
    up[v][0] = p;
    for(int i = 1; i<20; i++)
        up[v][i] = up[up[v][i-1]][i-1];
    long long best = 1e18;
    for(int i = 0; i<20; i++)
        best = min(best, 1ll*arr[v]+1ll*arr[up[v][i]]+1ll*i*arr[up[v][i]]);
    if(v == rt) best = 0ll;
    ans += best;
    for(auto u : adj[v])
        if(u != p) dfs(u, v);
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i<n; i++)
        cin >> arr[i];
    for(int i = 0; i<n-1; i++){
        int a, b; cin >> a >> b; --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    rt = min_element(arr, arr+n)-arr;
    dfs(rt, rt);
    cout << ans << endl;
}