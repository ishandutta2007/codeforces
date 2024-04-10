#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )

#define maxn 201010
int n;
vector<int> gr[maxn];
int a[maxn];
int ett[maxn], st[maxn], en[maxn], cur = 0;
void dfs(int u) {
  ett[cur] = a[u];
  st[u] = cur ++;
  for (auto v: gr[u]) dfs(v);
  en[u] = cur - 1;
}

int it[maxn * 4], lz[maxn * 4];
void build(int i = 1, int l = 0, int r = n - 1) {
  if (l == r) it[i] = ett[l], lz[i] = 0;
  if (l >= r) return;
  int mid = (l + r) / 2;
  build(i << 1, l, mid); build(i << 1 | 1, mid + 1, r);
  it[i] = it[i << 1] + it[i << 1 | 1];
}

void propagate(int i, int l, int r) {
  if (l > r or lz[i] == 0) return ;
  it[i] = r - l + 1 - it[i];
  lz[i] = 0;
  if (l < r) lz[i << 1] ^= 1, lz[i << 1 | 1] ^= 1;
}

void upd(int u, int v, int i = 1, int l = 0, int r = n - 1) {
  propagate(i, l, r);
  if (l > r or l > v or r < u) return ;
  if (u <= l and r <= v) {
    lz[i] ^= 1;
    propagate(i, l, r);
    return ;
  }
  int mid = (l + r) / 2;
  upd(u, v, i << 1, l, mid); upd(u, v, i << 1 | 1, mid + 1, r);
  it[i] = it[i << 1] + it[i << 1 | 1];
}

int get(int u, int v, int i = 1, int l = 0, int r = n - 1) {
  propagate(i, l, r);
  if (l > r or l > v or r < u) return 0;
  if (u <= l and r <= v) return it[i];
  int mid = (l + r) / 2;
  return get(u, v, i << 1, l, mid) + get(u, v, i << 1 | 1, mid + 1, r);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  for (int i = 1; ++i <= n; ) {
    int u; cin >> u;
    gr[u].push_back(i);
  }
  rep1(i, n) cin >> a[i];
  dfs(1);
  build();
  // rep1(i, n) clog << i << ' ' << st[i] << ' ' << en[i] << endl;
  int q; cin >> q;
  while (q--) {
    string cmd; int v;cin >> cmd >> v;
    if (cmd[0] == 'p') {
      upd(st[v], en[v]);
    } else {
      cout << get(st[v], en[v]) << '\n';
    }
  }
  
  return 0;
}