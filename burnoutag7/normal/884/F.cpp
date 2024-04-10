#include<bits/stdc++.h>
using namespace std;

const int N = 50+26+2+5, M = 2*(27*50+26)+5;
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

int n,a[105],c[26];
char s[105];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>s+1;
    for(int i=1;i<=n;i++)cin>>a[i],c[s[i]-'a']++;
    for(int i=0;i<26;i++)addedge(0,n/2+i+1,c[i],0);
    for(int i=1;i<=n/2;i++){
        for(int j=0;j<26;j++){
            int b=0;
            if(s[i]==j+'a')b=min(b,-a[i]);
            if(s[n+1-i]==j+'a')b=min(b,-a[n+1-i]);
            addedge(n/2+j+1,i,1,b);
        }
        addedge(i,n/2+27,2,0);
    }
    mcmf(0,n/2+27);
    cout<<-ret;

    return 0;
}