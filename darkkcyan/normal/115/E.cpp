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

#define maxn 201010
#define inf ((llong)1e17)
int n, m;

struct node {
  int l, r;
  llong val, lz;
  node *cl, *cr;
  node (int _l, int _r) : l(_l), r(_r), val(), lz(), cl(0), cr(0) {
    int mid = (l + r) / 2;
    if (l < r) cl = new node(l, mid), cr = new node(mid + 1, r);
  }

  void push() {
    val += lz;
    if (cl) {
      cl->lz += lz;
      cr->lz += lz;
    }
    lz = 0;
  }

  void upd(int ql, int qr, llong v) {
    push();
    if (l > qr or ql > r) return;
    if (ql <= l and r <= qr) {
      lz += v;
      push();
      return ;
    }
    cl->upd(ql, qr, v);
    cr->upd(ql, qr, v);
    val = max(cl->val, cr->val);
  }

  llong get(int ql, int qr) {
    push();
    if (l > qr or ql > r) return -inf;
    if (ql <= l and r <= qr) return val;
    return max(cl->get(ql, qr), cr->get(ql, qr));
  }

  ~node() {
    if (cl) delete cl, delete cr;
  }
};

llong fixcost[maxn];
pair<ii, llong> road[maxn];
llong dp[maxn];
int hasroad[maxn];

int main(void) {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  rep1(i, n) cin >> fixcost[i];
  rep1(i, m) {
    cin >> road[i].xx.yy >> road[i].xx.xx >> road[i].yy;
    hasroad[road[i].xx.yy]++;
    hasroad[road[i].xx.xx + 1]--;
  }

  node root(0, n);

  sort(road + 1, road + 1 + m);
  int ro = 0;
  //rep(f, n + 1) clog << root.get(f, f) << ' ';
  //clog << endl;
  rep1(i, n) {
    hasroad[i] += hasroad[i - 1];
    if (!hasroad[i]) fixcost[i] = 0;
    dp[i] = dp[i - 1];
    while (ro < m and road[ro + 1].xx.xx <= i) {
      ++ro;
      //clog << "upd road " << i << ' ' << road[ro] << endl;
      root.upd(0, road[ro].xx.yy - 1, road[ro].yy);
    }

    root.upd(0, i - 1, - fixcost[i]);
    dp[i] = max(dp[i], root.get(0, i - 1));
    //rep(f, n + 1) clog << root.get(f, f) << ' ';
    //clog << endl;
    root.upd(i, i, dp[i]);
  }
  //clog << tovec(dp, dp + n + 1) << endl;

  cout << dp[n];


  return 0;
}