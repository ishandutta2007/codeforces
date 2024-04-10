#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define len(x) ((int)x.size())

#define maxn 101010
int r, n;
int a[maxn];
vector<int> gr[maxn];

int st[maxn], en[maxn], cur = 1;
int ett[maxn];
int d[maxn];
void dfs(int u, int p) {
  d[u] = d[p] + 1;
  st[u] = cur++;
  ett[st[u]]  = u;
  for (auto v: gr[u])
    if (v != p) dfs(v, u);
  en[u] = cur - 1;
}

bool cmpv(int u, int v) { return d[u] < d[v]; }

struct node {
  vector<int> ver;
  vector<int> mi;
};

node operator+(const node& u, const node& v) {
  node ans;
  ans.ver.resize(len(u.ver) + len(v.ver));
  merge(u.ver.begin(), u.ver.end(), v.ver.begin(), v.ver.end(), ans.ver.begin(), cmpv);
  ans.mi.resize(len(ans.ver));
  ans.mi[0] = a[ans.ver[0]];
  rep1(i, len(ans.ver) - 1) {
    ans.mi[i] = min(ans.mi[i - 1], a[ans.ver[i]]);
  }
  return ans;
}

node it[maxn * 4];
void build(int i = 1, int l = 1, int r = n) {
  if (l == r) {
    it[i].ver.push_back(ett[l]);
    it[i].mi.push_back(a[ett[l]]);
  }
  if (l >= r) return;
  int mid = (l + r) / 2;
  build(i << 1, l, mid);
  build(i << 1 | 1, mid + 1, r);
  it[i] = it[i << 1] + it[i << 1 | 1];
}

int qu, qk;
int qr(int i = 1, int l = 1, int r = n) {
  int u = st[qu], v = en[qu];
  if (l > r or l > v or u > r) return INT_MAX;
  if (u <= l and r <= v) {
    int l = -1, r = len(it[i].ver) - 1;
    while (l < r) {
      int mid = l + (r - l + 1) / 2;
      if (d[it[i].ver[mid]] - d[qu] > qk) r = mid - 1;
      else l = mid;
    }
    if (l == -1) return INT_MAX;
    return it[i].mi[l];
  }
  int mid = (l + r) / 2;
  return min(qr(i << 1, l, mid), qr(i << 1 | 1, mid + 1, r));
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> r;
  rep1(i, n) cin >> a[i];
  rep(i, n - 1) {
    int u, v; cin >> u >> v;
    gr[u].push_back(v);
    gr[v].push_back(u);
  }

  dfs(r, r);
  build();
  int q; cin >> q;
  llong ans = 0;
  while (q--) {
    cin >> qu >> qk;
    qu = (qu + ans) % n + 1;
    qk = (qk + ans) % n;
    ans = qr();
    cout << ans << '\n';
  }

  return 0;
}