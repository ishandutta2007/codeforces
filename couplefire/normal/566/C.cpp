#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, cnt[N];
vector<array<int, 2>> adj[N];
int siz[N]; bool vis[N];
double deriv[N];
int ans1; double ans2 = 1e20;

void dfs(int v, int p){
    siz[v] = 1;
    for(auto u : adj[v]){
        if(u[0] == p || vis[u[0]]) continue;
        dfs(u[0], v);
        siz[v] += siz[u[0]];
    }
}

int centroid(int v){
    dfs(v, -1);
    int num = siz[v], p = -1;
    do{
        int nxt = -1;
        for(auto u : adj[v]){
            if(u[0] == p || vis[u[0]]) continue;
            if(siz[u[0]]*2 > num)
                nxt = u[0];
        }
        p = v, v = nxt;
    } while(~v);
    return p;
}

void calc(int v, int p, double& val, int dist, double& sum){
    sum += pow(dist, 1.5)*cnt[v]; val += 1.5*pow(dist, 0.5)*cnt[v];
    for(auto u : adj[v]){
        if(u[0] == p) continue;
        calc(u[0], v, val, dist+u[1], sum);
    }
}

void decomp(int v){
    v = centroid(v);
    double tot = 0, sum = 0;
    for(auto u : adj[v]){
        deriv[u[0]] = 0;
        calc(u[0], v, deriv[u[0]], u[1], sum);
        tot += deriv[u[0]];
    }
    if(sum < ans2) ans1 = v, ans2 = sum;
    vis[v] = 1;
    for(auto u : adj[v]){
        if(vis[u[0]]) continue;
        if(tot-2*deriv[u[0]] >= 0) continue;
        decomp(u[0]);
        break;
    }
}

int main(){
    // freopen("a.in", "r", stdin);
    cout << fixed << setprecision(10);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i<n; i++)
        cin >> cnt[i];
    for(int i = 0; i<n-1; i++){
        int a, b, w; cin >> a >> b >> w; --a; --b;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    decomp(0);
    cout << ans1+1 << " " << ans2 << endl;
}