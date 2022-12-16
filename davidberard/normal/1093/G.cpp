#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 200200;
vector<int> pt[N];
const int INF = 0x3f3f3f3f;
int n, k;

struct Segtree {
  vector<int> t;
  int n, h;
  Segtree(int sz) {
    h = 32 - __builtin_clz(sz);
    n = 1<<h;
    t = vector<int>(n<<1, INF);
  }
  void assign(int x, int v) {
    x += n;
    t[x] = v;
    for (x/=2; x; x/=2) {
      t[x] = min(t[x<<1], t[x<<1|1]);
    }
  }
  int query(int l, int r) {
    int ans = INF;
    for (l+=n, r+=n; l<r; l/=2, r/=2) {
      if (l%2) {
        ans = min(ans, t[l]);
        ++l;
      }
      if (r%2) {
        --r;
        ans = min(ans, t[r]);
      }
    }
    return ans;
  }
};

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k;
  vector<Segtree> mx(1<<k, n+10), mn(1<<k, n+10);
  for (int i=1; i<=n; ++i) {
    for (int j=0; j<k; ++j) {
      int x;
      cin >> x;
      pt[i].push_back(x);
    }
    for (int r=0; r<(1<<k); ++r) {
      int res = 0;
      for (int x=0; x<k; ++x) {
        res += ((r&(1<<x)) ? 1 : -1)*pt[i][x];
      }
      mx[r].assign(i, -res);
      mn[r].assign(i, res);
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int j;
      cin >> j;
      for (int r=0; r<k; ++r) {
        int x;
        cin >> x;
        pt[j][r] = x;
      }
      for (int r=0; r<(1<<k); ++r) {
        int res = 0;
        for (int x=0; x<k; ++x) {
          res += ((r&(1<<x)) ? 1 : -1)*pt[j][x];
        }
        mx[r].assign(j, -res);
        mn[r].assign(j, res);
      }
    } else if (type == 2) {
      int l, rv;
      cin >> l >> rv;
      int ans = 0;
      for (int r=0; r<(1<<k); ++r) {
        ans = max(ans, -(mx[r].query(l, rv+1) + mn[r].query(l, rv+1)));
      }
      cout << ans << "\n";
    }
  }
  return 0;
}