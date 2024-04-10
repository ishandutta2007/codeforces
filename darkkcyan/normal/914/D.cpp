#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define len(x) ((int)x.size())

#define maxn 501010
int n;
llong a[maxn];
llong it[maxn * 4];
void build(int i = 1, int l = 1, int r = n) {
  if (l == r) it[i] = a[l];
  if (l >= r) return ;
  int mid = (l + r) / 2;
  build(i << 1, l, mid);
  build(i << 1 | 1, mid + 1, r);
  it[i] = __gcd(it[i << 1], it[i << 1 | 1]);
}

void up(int pos, int i = 1, int l = 1, int r = n) {
  if (l > r or l > pos or r < pos) return ;
  if (l == r) {
    it[i] = a[l];
    return ;
  }
  int mid = (l + r) / 2;
  up(pos, i << 1, l, mid);
  up(pos, i << 1 | 1, mid + 1, r);
  it[i] = __gcd(it[i << 1], it[i << 1 | 1]);
}

vector<pair<int, ii> > part;
void getpart(int u, int v, int i = 1, int l = 1, int r = n) {
  if (l > r or l > v or r < u) return ;
  if (u <= l and r <= v) {
    part.push_back({i, {l, r}});
    return ;
  }
  int mid = (l + r) / 2;
  getpart(u, v, i << 1, l, mid);
  getpart(u, v, i << 1 | 1, mid + 1, r);
}

int findl(int x, int i, int l, int r) {
  assert(l <= r);
  ////clog << i << ' ' << l << ' ' << r << ' ' << it[i] % x << ' ' << it[i] << endl;
  if (it[i] % x == 0) return r;
  if (l == r) return l - 1;
  int mid = (l + r) / 2;
  if (it[i << 1] % x == 0) return findl(x, i << 1 | 1, mid + 1, r);
  else return findl(x, i << 1, l, mid);
}

int findr(int x, int i, int l, int r) {
  assert(l <= r);
  //clog << l << ' ' << r << ' ' << it[i] % x << ' ' << it[i] << endl;
  if (it[i] % x == 0) return l;
  if (l == r) return r + 1;
  //clog << l << ' ' << r << ' ' << it[i] % x << ' ' << it[i] << endl;
  int mid = (l + r) / 2;
  if (it[i << 1 | 1] % x == 0) return findr(x, i << 1, l, mid);
  else return findr(x, i << 1 | 1, mid + 1, r);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  rep1(i, n) cin >> a[i];
  build();
  clog << it[1] << endl;
  int q; cin >> q;
  while (q--) {
    int type; cin >> type;
    if (type == 2) {
      int pos; cin >> pos; cin >> a[pos];
      up(pos);
    } else {
      int u, v, x; cin >> u >> v >> x;
      part.clear();
      getpart(u, v);
      int l = u - 1, r = v + 1;
      for (auto i: part) {
        int t = findl(x, i.xx, i.yy.xx, i.yy.yy);
        l = t;
        if (t != i.yy.yy) break;
      }
      //for (auto i: part) clog << i.yy.xx << ' ' << i.yy.yy << ';';
      //clog << endl;
      reverse(part.begin(), part.end());
      for (auto i: part) {
        int t = findr(x, i.xx, i.yy.xx, i.yy.yy);
        r = t;
        if (t != i.yy.xx) break;
      }
      //clog << l << ' ' << r << endl;
      if (l >= r or r - l <= 2) cout << "YES\n";
      else cout << "NO\n";
    }
  }

  return 0;
}