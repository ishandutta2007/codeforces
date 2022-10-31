#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005

vector<long long> adj[MAXN];
long long depth[MAXN];
long long numchild[MAXN];
vector<long long> extra;
long long n, k;

void dfs(long long v, long long p, long long d){
    depth[v] = d;
    for(auto u : adj[v]){
        if(u == p) continue;
        dfs(u, v, d+1);
        numchild[v] += 1+numchild[u];
    }
    extra.push_back(depth[v]-numchild[v]);
}

int main(){
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for(long long i = 0; i<n-1; i++){
        long long a, b; cin >> a >> b;
        --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0, -1, 0);
    sort(extra.begin(), extra.end());
    reverse(extra.begin(), extra.end());
    long long sum = 0;
    for(long long i = 0; i<k; i++) sum += extra[i];
    cout << sum << endl;
}