#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )

#define maxn 501010
int n, m;
vector<int> gr[maxn];

int l[maxn], r[maxn], cur = 0;
void dfs(int u, int p) {
  l[u] = cur ++;
  for (auto v: gr[u]) {
    if (v != p) dfs(v, u);
  }
  r[u] = cur - 1;
}

int it1[maxn * 4] = {0}, lz[maxn * 4], it2[maxn * 4];
void propagate(int i, int l, int r) {
  if (l > r or lz[i] == -1) return;
  it1[i] = lz[i];
  if (l < r) lz[i << 1] = lz[i << 1 | 1] = lz[i];
  lz[i] = -1;
}

void upd1(int u, int v, int val, int i = 1, int l = 0, int r = n - 1) {
  propagate(i, l, r);
  if (l > r or l > v or u > r) return;
  if (u <= l and r <= v) {
    lz[i] = val;
    propagate(i, l, r);
    return;
  }
  int mid = (l + r) / 2;
  upd1(u, v, val, i << 1, l, mid);
  upd1(u, v, val, i << 1 | 1, mid + 1, r);
  it1[i] = max(it1[i << 1], it1[i << 1 | 1]);
}

void upd2(int id, int val, int i = 1, int l = 0, int r = n - 1) {
  if (l > r or l > id or r < id) return ;
  if (l == r) {
    it2[i] = val;
    return ;
  }
  int mid = (l + r) / 2;
  upd2(id, val, i << 1, l, mid);
  upd2(id, val, i << 1 | 1, mid + 1, r);
  it2[i] = max(it2[i << 1], it2[i << 1 | 1]);
}

int get1(int id, int i = 1, int l = 0, int r = n - 1) {
  propagate(i, l, r);
  if (l == r) return it1[i];
  int mid = (l + r) / 2;
  return id <= mid ? get1(id, i << 1, l, mid) : get1(id, i << 1 | 1, mid + 1, r);
}
int get2(int u, int v, int i = 1, int l = 0, int r = n - 1) {
  if (l > r or l > v or r < u) return 0;
  if (u <= l and r <= v) return it2[i];
  int mid = (l + r) / 2;
  return max(get2(u, v, i << 1, l, mid), get2(u, v, i << 1 | 1, mid + 1, r));
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  rep(i, n - 1) {
    int u, v; cin >>u >> v;
    gr[u].push_back(v);
    gr[v].push_back(u);
  }
  
  dfs(1, 1);
  assert(cur == n);
  memset(lz, 0, sizeof(lz));

  cin >> m;
  rep1(i, m) {
    int t, u; cin >> t >> u;
    if (t == 3) {
      int x = get1(l[u]);
      int y = get2(l[u], r[u]);
      // clog << u << ' ' << x << ' ' << y << endl;
      cout << (x > y) << '\n';
    }
    else if (t == 1) 
      upd1(l[u], r[u], i);
    else
      upd2(l[u], i);
    // rep1(i, n) {
    //   // clog << i << ' ' << get1(l[u]) << ' ' << get2(l[u], r[u]) << endl;
    // }
    // // clog << endl;
      
  }
  
  return 0;
}