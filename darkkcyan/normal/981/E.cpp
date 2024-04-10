#include<bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )
#define xx first
#define yy second

#define maxn 10101
#define maxm maxn
vector<int> it[maxn * 4];
int n, q;

void add(int v, int ql, int qr, int i = 1, int l = 1, int r = n) {
  //clog << i << ' ' << l << ' ' << r << endl;
  if (l > r or l > qr or ql > r) return ;
  if (ql <= l and r <= qr) {
    it[i].push_back(v);
    return;
  }
  int mid = (l + r) / 2;
  add(v, ql, qr, i << 1, l, mid);
  add(v, ql, qr, i << 1 | 1, mid + 1, r);
}

bitset<maxm> ans;
vector<bitset<maxm> > bsst;
void getans(int i = 1, int l = 1, int r = n) {
  //clog << i << ' ' << l << ' ' << r << endl;
  if (l > r) return ;
  bitset<maxm> bs = bsst.back();
  for (auto f: it[i]) {
    bs |= bs << f;
  }
  //clog << i << ' ' << l << ' ' << r << ' ' << bs << endl;
  if (l == r) {
    ans = ans | bs;
    return;
  }
  bsst.push_back(bs);
  int mid = (l + r) / 2;
  getans(i << 1, l, mid);
  getans(i << 1 | 1, mid + 1, r);
  bsst.pop_back();
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> q;
  rep(i, q) {
    int l, r, u; cin >> l >> r >> u;
    add(u, l, r);
  }
  //clog << " OK" << endl;

  bsst.push_back(bitset<maxm>());
  bsst[0][0] = 1;
  getans();
  vector<int> res;
  rep1(i, n) if (ans[i]) res.push_back(i);
  cout << len(res) << '\n';
  for (auto i: res) cout << i << ' ' ;

  return 0;
}