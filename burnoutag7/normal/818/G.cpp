#include<bits/stdc++.h>
using namespace std;

const int N = 6e3 + 5, M = 1e5 + 5;
const int INF = 0x3f3f3f3f;
int tot = 1, lnk[N], cur[N], ter[M], nxt[M], cap[M], cost[M], dis[N], ret;
bool vis[N];

void add(int u, int v, int w, int c) {
  ter[++tot] = v, nxt[tot] = lnk[u], lnk[u] = tot, cap[tot] = w, cost[tot] = c;
}
void addedge(int u, int v, int w, int c) { add(u, v, w, c), add(v, u, 0, -c); }
bool spfa(int s, int t) {
  memset(dis, 0x3f, sizeof(dis));
  memcpy(cur, lnk, sizeof(lnk));
  std::queue<int> q;
  q.push(s), dis[s] = 0, vis[s] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop(), vis[u] = 0;
    for (int i = lnk[u]; i; i = nxt[i]) {
      int v = ter[i];
      if (cap[i] && dis[v] > dis[u] + cost[i]) {
        dis[v] = dis[u] + cost[i];
        if (!vis[v]) q.push(v), vis[v] = 1;
      }
    }
  }
  return dis[t] != INF;
}
int dfs(int u, int t, int flow) {
  if (u == t) return flow;
  vis[u] = 1;
  int ans = 0;
  for (int &i = cur[u]; i && ans < flow; i = nxt[i]) {
    int v = ter[i];
    if (!vis[v] && cap[i] && dis[v] == dis[u] + cost[i]) {
      int x = dfs(v, t, std::min(cap[i], flow - ans));
      if (x) ret += x * cost[i], cap[i] -= x, cap[i ^ 1] += x, ans += x;
    }
  }
  vis[u] = 0;
  return ans;
}
int mcmf(int s, int t) {
  int ans = 0;
  while (spfa(s, t)) {
    int x;
    while ((x = dfs(s, t, INF))) ans += x;
  }
  return ans;
}

int n,a[3005],nx[100005],nm[15];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    fill(nx+1,nx+100001,n+1);
    fill(nm,nm+7,n+1);
    for(int i=n;i>=1;i--){
        addedge(n*2+2,i*2-1,1,0);
        addedge(i*2-1,i*2,1,-1);
        addedge(i*2,n*2+1,1,0);

        addedge(i*2-1,nx[a[i]]*2-1,1,0);
        for(int j=i+1;j<=n;j++)if(a[i]-1==a[j]){
            addedge(i*2,j*2-1,1,0);
            break;
        }
        for(int j=i+1;j<=n;j++)if(a[i]+1==a[j]){
            addedge(i*2,j*2-1,1,0);
            break;
        }
        nx[a[i]]=i;

        addedge(i*2-1,nm[a[i]%7]*2-1,1,0);
        for(int j=i+1;j<=n;j++)if(a[i]%7==a[j]%7){
            addedge(i*2,j*2-1,1,0);
            break;
        }
        nm[a[i]%7]=i;
    }
    addedge(0,n*2+2,4,0);
    mcmf(0,n*2+1);
    cout<<-ret;

    return 0;
}