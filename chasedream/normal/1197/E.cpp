#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 200005;
struct Doll {
  int out, in;
  bool operator < (const Doll& b) const {
    return in < b.in;
  }
} a[N];

struct Edge {
  int to, nxt, val;
  Edge(int to = 0, int nxt = 0, int val = 0):
    to(to), nxt(nxt), val(val) {}
} edge[N << 1];
int head[N], tot;

void add(int u, int v, int val) {
  /*
  printf("*** new Edge!\n");
  printf("(%d -> %d, val = %d)\n", u, v, val);
  putchar('\n');
  */
  edge[++tot] = (Edge){v, head[u], val};
  head[u] = tot;
}

int n;

int Erfen(int x) {
  int l = 1, r = n;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (a[mid].in >= x) r = mid;
    else l = mid + 1;
  }
  if (a[l].in >= x) return l;
  else return -1;
}

const int mod = 1e9 + 7;
ll dis[N], cnt[N];
bool vis[N];

void topo() {
  memset(dis, 0x7f7f7f, sizeof(dis));
  memset(cnt, 0, sizeof(cnt));
  memset(vis, 0, sizeof(vis));
  cnt[0] = 1LL, dis[0] = 0LL;

  for (int i = 0; i <= n; i++) {
    for (int j = head[i]; j != -1; j = edge[j].nxt) {
      int v = edge[j].to;
      if (dis[v] > dis[i] + edge[j].val) {
        dis[v] = dis[i] + edge[j].val;
        cnt[v] = cnt[i];
      } else if (dis[v] == dis[i] + edge[j].val) {
        (cnt[v] += cnt[i]) %= mod;
      }
    }
  }
}

int main() {
  memset(head, -1, sizeof(head));
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &a[i].out, &a[i].in);
  }
  sort(a + 1, a + n + 1);
  /*
  printf("*** debug sort\n");
  for (int i = 1; i <= n; i++) {
    printf("%d-> (%d, %d)\n", i, a[i].out, a[i].in);
  } 
  printf("*** end, sort\n");
  */
  for (int i = 0; i < n; i++) {
    add(i, i + 1, a[i + 1].in - a[i].in);
  }
  for (int i = 1; i <= n; i++) {
    int up = Erfen(a[i].out);
    if (up == -1) continue;
    add(i, up, a[up].in - a[i].out);
  }
  topo();

  ll ans = 0LL, mindis = 1e15;
  for (int i = 1; i <= n; i++) {
    if (a[i].out > a[n].in)
      mindis = min(mindis, dis[i]);
  }

  for (int i = 1; i <= n; i++) {
    //printf("cnt[%d] = %lld\n", i, cnt[i]);
    //printf("dis[%d] = %lld\n", i, dis[i]);
    if (a[i].out > a[n].in && mindis == dis[i])
      (ans += cnt[i]) %= mod;
  }
  printf("%lld\n", ans);

  return 0;
}