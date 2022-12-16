#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

struct Segtree {
  vector<int> t;
  int n, h;
  Segtree() {}
  Segtree(int sz) {
    h = 32 - __builtin_clz(sz);
    n = 1<<h;
    t = vector<int>(n<<1);
  }
  void assign(int x, int v) {
    x += n;
    t[x] = v;
    for (x/=2; x; x/=2) {
      t[x] = max(t[x<<1], t[x<<1|1]);
    }
  };
  int query(int l, int r) {
    int ans = 0;
    for (l+=n, r+=n; l<r; l/=2, r/=2) {
      if (l%2) {
        ans = max(ans, t[l++]);
      }
      if (r%2) {
        ans = max(ans, t[--r]);
      }
    }
    return ans;
  }
};

struct Dom {
  int x, h, i;
  bool operator< (const Dom& o) const {
    return x < o.x;
  }
};

int ans[100100];
int f[100100];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  vector<Dom> doms(n);
  for (int i=1; i<=n; ++i) {
    cin >> doms[i-1].x >> doms[i-1].h;
    doms[i-1].i = i;
  }
  doms.push_back({(int) 1e9, 1, n+1});

  Segtree st(n+4);

  sort(doms.begin(), doms.end());
  ans[doms[n-1].i] = f[n-1] = 1;
  st.assign(n-1, 1+(n-1));
  for (int i=n-2; i>=0; --i) {
    int lo = i+1, hi = n;
    while (lo<hi) {
      int mid = (lo+hi)/2;
      if (doms[i].h > doms[mid].x-doms[i].x) {
        lo = mid+1;
      } else {
        hi = mid;
      }
    }

    if (lo > i+1) {
      f[i] = st.query(i+1, lo) - i;
    } else {
      f[i] = 1;
    }

    ans[doms[i].i] = f[i];
    st.assign(i, i+f[i]);
  }

  for (int i=1; i<=n; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;

  return 0;
}