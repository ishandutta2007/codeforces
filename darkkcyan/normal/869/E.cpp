#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )

#define maxn 2555
#define maxm 101010
struct bit {
  llong d[maxn][maxn];
  map<pair<ii, ii>, llong> hs;

  void add(int r, int c, llong x) {
    ++c;
    for (++r; r < maxn; r += r & -r)
    for (int i = c; i < maxn; i += i & -i) {
      d[r][i] ^= x;
    }
  }
  llong get(int r, int c) {
    llong ans = 0;

    // clog << r << ' ' << c << ' ';
    for (++r; r > 0; r -= r & -r) {
      for (int i = c + 1; i > 0; i -= i & -i)
        ans ^= d[r][i];
    }
    // clog << ans << endl;
    return ans;
  }
  
  void addrect(int r1, int c1, int r2, int c2) {
    pair<ii, ii> x = {{r1, c1}, {r2, c2}};
    if (!hs.count(x)) hs[x] = ((llong)rand() * (llong)rand()) & ((1ll << 62) - 1);
    llong val = hs[x];
    // clog << r1 << ' ' << c1 << ' ' << r2 << ' ' << c2 << ' ' << val << endl;

    add(r1, c1, val);
    add(r1, c2 + 1, val);
    add(r2 + 1, c1, val);
    add(r2 + 1, c2 + 1, val);
  }
};

bit b1, b2;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  srand(time(0));
  int n, m, q; cin >> n >> m >> q;
  while (q--) {
    int t, r1, c1, r2, c2; cin >> t >> r1 >> c1 >> r2 >> c2;
    if (t == 3) {
      if (b1.get(r1, c1) == b1.get(r2, c2) and b2.get(r1, c1) == b2.get(r2, c2)) {
        cout << "Yes\n";
      } else {
        cout << "No\n";
      }
    } else {
      b1.addrect(r1, c1, r2, c2);
      b2.addrect(r1, c1, r2, c2);
    }
  }
  
  return 0;
}