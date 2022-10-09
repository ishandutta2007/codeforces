#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define len(x) ((int)x.size())
#define maxn 201010

struct ds {
  llong cnt[1 << 20];
  vector<int> active;
  ds(): cnt() {
    memset(cnt, 0, sizeof(cnt));
  }
  void clear() { if (len(active)) for (auto i: active) cnt[i] = 0; active.clear(); }
  void add(int i, int f) {
    if (cnt[i] == 0) active.push_back(i);
    cnt[i] += f;
  }
  llong getsum(int i) {
    const llong r = (1 << 20) - 1;
    llong ans = cnt[(0 ^ i) & r];
    rep(f, 20) {
      ans += cnt[(0 ^ i ^ (1 << f)) & r];
    }
    return ans;
  }
} ds;

int n;
string s;
vector<int> gr[maxn];


template<int nn> struct centroiddecomposition {
  int n;
  vector<int> gr[nn];
  bool mark[nn];
  int childcnt[nn];
  centroiddecomposition() {
    memset(mark, 0, sizeof(mark));
  }
  
  void dfscountchild(int u, int p) {
    childcnt[u] = 1;
    for (auto v: gr[u]) {
      if (v == p or mark[v]) continue;
      dfscountchild(v, u);
      childcnt[u] += childcnt[v];
    }
  }
  
  int findcen(int u) {
    dfscountchild(u, u);
    int pcnt = 0, p = u, total = childcnt[u];
    while (1) {
      int maxcnt = pcnt, bigchild= -1;
      for (auto v: gr[u])
        if (!mark[v] and v != p and childcnt[v] > maxcnt)
          maxcnt = childcnt[v], bigchild = v;
      if (maxcnt <= total / 2) break;
      assert(bigchild != -1);
      p = u; u = bigchild;
      pcnt = total - childcnt[u];
    }
    mark[u] = 1;
    return u;
  }
};

centroiddecomposition<maxn> cd;

void dfs1(int u, int p, int mask, int fac) {
  mask ^= (1 << (s[u] - 'a'));
  ds.add(mask, fac);
  for (auto v: gr[u]) {
    if (v == p or cd.mark[v]) continue;
    dfs1(v, u, mask, fac);
  }
}

llong tempdp[maxn] = {0}, ans[maxn] = {0};
void dfs2(int u, int p, int mask, bool addans) {
  mask ^= 1 << (s[u] - 'a');
  tempdp[u] = ds.getsum(mask);
  for (auto v: gr[u]) {
    if (cd.mark[v] or p == v) continue;
    dfs2(v, u, mask, addans);
    tempdp[u] += tempdp[v];
    tempdp[v] = 0;
  }
  if (addans) ans[u] += tempdp[u];
  //clog << u << ' ' << tempdp[u] << endl;
}

void process(int u) {
  u = cd.findcen(u);
  //clog << "cen " << u << endl;
  ds.clear();
  dfs1(u, u, 0, 1);
  for (auto v: gr[u]) {
    if (cd.mark[v]) continue;
    dfs1(v, u, 1 << (s[u] - 'a'), -1);
    dfs2(v, u, 0, 1);
    //clog << tempdp[v] << endl;
    tempdp[v] = 0;
    dfs1(v, u, 1 << (s[u] - 'a'), 1);
  }
  for (auto v: gr[u]) {
    if (cd.mark[v]) continue;
    dfs1(v, u, 1 << (s[u] - 'a'), -1);
    dfs2(v, u, 0, 0);
    //clog << tempdp[v] << endl;
    tempdp[u] += tempdp[v];
    tempdp[v] = 0;
  }
  ans[u] += tempdp[u];
  //clog << u << ' ' << tempdp[u] << endl;
  tempdp[u] = 0;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  rep(i, n - 1) {
    int u, v; cin >> u >> v;
    gr[u].push_back(v);
    gr[v].push_back(u);
  }
  cd.n = n;
  rep1(i, n) cd.gr[i] = gr[i];
  cin >> s;
  s = ' ' + s;
  rep1(i, n) {
    while (!cd.mark[i]) process(i);
  }
  rep1(i, n) cout << ans[i] + 1 << ' ';

  return 0;
}