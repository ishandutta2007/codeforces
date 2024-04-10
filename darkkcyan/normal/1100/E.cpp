#include <bits/stdc++.h>
using namespace std;

#define cli clog << "\"" << __PRETTY_FUNCTION__ << "\"@" << __LINE__ << ": "/*{{{*/
#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
template<class x> vector<typename x::value_type> tovec(const x& a) { return vector<typename x::value_type>(a.begin(), a.end()); }
#define ptrtype(x) typename iterator_traits<x>::value_type
template<class u> vector<ptrtype(u)> tovec(u a, u b) { return vector<ptrtype(u)>(a, b); }
template<typename x> ostream& operator<<(ostream& cout, const vector<x>& a) {
  cout << "[";
  if (len(a)) cout << a[0];
  rep1(i, len(a) - 1) cout << ", " << a[i];
  return cout << "]";
}
template<typename u, typename v> ostream& operator<<(ostream& cout, const pair<u, v>& a) {
  return cout << "(" << a.xx << ", " << a.yy << ")";
}/*}}}*/

#define maxn 101010
int n, m;
pair<llong, ii> el[maxn];

vector<int> gr[maxn];

int col[maxn];
bool checkcycle(int u) {
  col[u] = 1;
  bool ans = false;
  for (auto v: gr[u]) {
    if (col[v] == 2) continue;
    if (col[v] == 1 || checkcycle(v)) {
      ans = true;
      break;
    }
  }
  col[u] = 2;
  return ans;
}

int tporder[maxn], curtp = 0;
void dfs(int u) {
  tporder[u] = 0;
  for (auto v: gr[u]) {
    if (tporder[v] == -1) dfs(v);
  }
  tporder[u] = curtp++;
}

bool ok(llong mincost) {
  rep1(i, n) gr[i].clear();
  rep(i, m) {
    int u = el[i].yy.xx, v = el[i].yy.yy;
    llong c = el[i].xx;
    if (c < mincost) continue;
    gr[u].push_back(v);
  }
  memset(col, 0, sizeof(col));
  rep1(i, n) {
    if (col[i] == 2) continue;
    if (checkcycle(i)) return true;
  }
  return false;
}

int main(void) {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  vector<int> pos(m);
  llong l = 0, r = 0;
  rep(i, m) {
    cin >> el[i].yy.xx >> el[i].yy.yy >> el[i].xx;
    pos[i] = i;
    r = max(r, el[i].xx);
  }

  while (l < r) {
    llong mid = l + (r - l + 1) / 2;
    if (ok(mid)) l = mid;
    else r = mid - 1;
  }

  llong ans = l;

  vector<int> rest;
  rep1(i, n) {
    gr[i].clear();
  }

  rep(i, m) {
    int u = el[i].yy.xx, v = el[i].yy.yy;
    llong c = el[i].xx;
    if (c <= ans) rest.push_back(i);
    else gr[u].push_back(v);
  }
  memset(tporder, -1, sizeof(tporder));
  clog << rest << endl;

  rep1(i, n) if (tporder[i] == -1) dfs(i);
  vector<int> anslist;
  for (auto i: rest) {
    int u = el[i].yy.xx, v = el[i].yy.yy;
    //llong c = el[i].xx;
    if (tporder[u] > tporder[v]) continue;
    anslist.push_back(i);
  }
  cout << ans << ' ' << len(anslist) << '\n';
  for (auto i: anslist) cout << i + 1 << ' ';

  return 0;
}