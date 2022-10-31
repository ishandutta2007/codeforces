//created by missever
 
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> P;
 
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
int f[55][55][55][55],d[55];
bool vis[55];
vector<P> g[55];
 
void dfs(int u,int fa) {
    for(auto e:g[u]) {
        if(e.first == fa) continue;
        dfs(e.first,u);
        d[u] += d[e.first];
    }
}
 
int solve(int u,int v,int m,int k,int ds) {
    int &w = f[u][v][m][k];
    if(w != -1) return w;
    if(m == 0) w = 0;
    else if(vis[v]) w = solve(v,u,m - k,m - k,g[v][0].second) + ds;
    else {
        int l = 1,r = 100000000;
        while(l < r) {
            int mid = (l + r) >> 1;
            int i,s = 0;
            for(auto e:g[v]) {
                if(e.first == u) continue;
                for(i = 1;i <= k; i++) {
                    if(solve(v,e.first,m,i,e.second) <= mid) break;
                }
                s += i - 1;
            }
            if(s >= k) l = mid + 1;
            else r = mid;
        }
        w = r + ds;
    }
    //cout<<u<<" "<<v<<" "<<m<<" "<<k<<" "<<w<<endl;
    return w;
}
 
int main() {
#ifdef CX_TEST
    freopen("E:\\program--GG\\test_in.txt", "r", stdin);
#endif
    int n,m,i,u,v,w;
    memset(f,-1,sizeof(f));
    scanf("%d",&n);
    for(i = 1;i < n; i++) {
        scanf("%d%d%d",&u,&v,&w);
        g[u].push_back(P(v,w));
        g[v].push_back(P(u,w));
    }
    scanf("%d",&u);
    scanf("%d",&m);
    for(i = 0;i < m; i++) {
        scanf("%d",&v);
        d[v]++;
    }
    m -= d[u];
    dfs(u,0);
    //cout<<-1<<endl;
    for(i = 1;i <= n; i++) vis[i] = (g[i].size() == 1);
    int ans = mod;
    for(auto e:g[u]) {
        //cout<<e.first<<" "<<e.second<<endl;
        if(d[e.first]) ans = min(ans,solve(u,e.first,m,d[e.first],e.second));
    }
    printf("%d\n",ans);
    return 0;
}