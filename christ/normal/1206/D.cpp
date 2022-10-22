#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
char _;
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
typedef pair<ld,ld> line;
template <typename t> void scan (t& x) {do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0);}
template <typename t, typename ...r> void scan (t& x, r&... xs) {scan(x); scan(xs...);}
const int MN = 2e5+2;
int cnt[64], ans = INT_MAX;
vector<int> which[64];
vector<int> adj[MN];
ll a[MN];
bool vis[MN], onpath[MN];
int dist[MN];
void dfs (int cur) {
    vis[cur] = 1;
    onpath[cur] = 1;
    for (int i : adj[cur]) {
        if (onpath[i] && dist[cur] - dist[i] > 1) ans = min(ans,dist[cur] - dist[i] + 1);
        else if (!vis[i]) dist[i] = dist[cur] + 1, dfs(i);
    }
    onpath[cur] = 0;
}
void unvis (int cur) {
    vis[cur] = 0;
    onpath[cur] = 0;
    for (int i : adj[cur]) if (vis[i]) unvis(i);
}
int main () {
    int n;
    scanf ("%d",&n);
    for (int i = 0; i < n; i++) {
        scanf ("%lld",&a[i]);
        for (int j = 0; j < 64; j++) if ((a[i]>>j)&1) ++cnt[j];
    }
    for (int i = 0; i < 64; i++) if (cnt[i] >= 3) return !printf ("3\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 64; j++) if ((a[i]>>j)&1) {
            which[j].push_back(i);
        }
    }
    for (int i = 0; i < 64; i++) if (which[i].size() == 2){
        adj[which[i][0]].push_back(which[i][1]);
        adj[which[i][1]].push_back(which[i][0]);
    }
    for (int i = 0; i < n; i++) dist[i] = 0, dfs(i), unvis(i);
    printf ("%d\n",ans>1e9 ? -1 : ans);
    return 0;
}