#include <bits/stdc++.h>
using namespace std;

#define llong long long /*{{{*/
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

struct line;
typedef multiset<line>::iterator mslitor;
struct line {
  llong k, b;
  mutable mslitor curNode;

  line() {}
  line(llong ak, llong ab): k(ak), b(ab) {}

  llong cal(llong x) const { return x * k + b; }
};
ostream& operator<<(ostream& cout, const line& a) {
  return cout << make_pair(a.k, a.b);
}


bool check(const line& l1, const line& l2, const line& t) {
  return (long double) (t.k - l2.k) * (l1.b - l2.b) >= (long double)(t.b - l2.b) * (l1.k - l2.k);
}


multiset<line>* containerSet = 0;
bool operator<(const line& u, const line& v) {
  //clog << u << ' ' << v << endl;
  if (!containerSet) return u.k > v.k;
  //clog << "OK" << ' ' << *u.curNode << endl;
  auto nxt = next(u.curNode);
  //clog << "OK" << endl;
  if (nxt == containerSet->end()) return false;
  //clog << *nxt << endl;
  return u.cal(v.b) > nxt->cal(v.b);
}

struct lineContainer : multiset<line> {  // manages lower hull
  bool isAboveHull(iterator itor) {
    if (size() == 1) return false;
    if (itor == begin()) return (itor->k == next(itor)->k) and (itor->b > next(itor)->b);
    if (next(itor) == end()) return itor->b > prev(itor)->b and itor->k == prev(itor)->k;
    return check(*prev(itor), *itor, *next(itor));
  }

  void insert(line x) {
    mslitor nn = multiset<line>::insert(x);
    nn->curNode = nn;
    if (isAboveHull(nn)) {
      erase(nn);
      return ;
    }
    while (next(nn) != end() and isAboveHull(next(nn))) erase(next(nn));
    while (nn != begin() and isAboveHull(prev(nn))) erase(prev(nn));
  }

  llong query(llong x) {
    containerSet = this;
    llong ans = lower_bound(line(0, x))->cal(x);
    containerSet = 0;
    return ans;
  }
};

#define maxn 101010
int n;
llong a[maxn], b[maxn];
vector<int> gr[maxn];
lineContainer lc[maxn];
llong ans[maxn];

void dfs(int u, int p) {
  int big = -1;
  for (auto v: gr[u]) {
    if (v == p) continue;
    dfs(v, u);
    if (big == -1 or len(lc[big]) < len(lc[v])) big = v;
    //clog << v << ' ' << tovec(lc[v]) << endl;
  }

  //clog << u << ' ' << big << endl;

  if (big == -1) {
    ans[u] = 0;
    lc[u].insert(line(b[u], 0));
    return ;
  }

  lc[u] = move(lc[big]);
  for (auto v: gr[u]) {
    if (v == p or v == big) continue;
    for (auto nl: lc[v]) {
      lc[u].insert(nl);
    }
    lc[v].clear();
  }
  ans[u] = lc[u].query(a[u]);
  lc[u].insert(line(b[u], ans[u]));
  //clog << u << ' ' << tovec(lc[u]) << endl;
}


int main(void) {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  rep1(i, n) cin >> a[i];
  rep1(i, n) cin >> b[i];
  rep(_, n - 1) {
    int u, v; cin >> u >> v;
    gr[u].push_back(v);
    gr[v].push_back(u);
  }

  dfs(1, 1);
  rep1(i, n) cout << ans[i] << ' ';


  return 0;
}