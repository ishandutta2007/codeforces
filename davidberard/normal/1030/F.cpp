#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const ll MOD = 1e9+7;

ll tx[1<<19], t[1<<19];

struct SegtreeMOD {
  //vector<ll> tx;
  int n, h;
  SegtreeMOD() {}
  SegtreeMOD(int sz) {
    h = 32 - __builtin_clz(sz);
    n = 1<<h;
    //tx = vector<ll>(n<<1);
  }
  void aset(int x, ll v) {
    tx[x+n] = v%MOD;
  }
  void build() {
    for (int x=n-1; x; --x) {
      tx[x] = tx[x<<1]+tx[x<<1|1];
      if (tx[x] >= MOD) {
        tx[x] -= MOD;
      }
    }
  }
  void assign(int x, ll v) {
    x +=n;
    tx[x] = v%MOD;
    for (x/=2; x; x/=2) {
      tx[x] = (tx[x<<1]+tx[x<<1|1]);
      if (tx[x] >= MOD) {
        tx[x] -= MOD;
      }
    }
  }
  
  ll query(int l, int r) {
    ll ans = 0;
    for (l+=n, r+=n; l<r; l/=2, r/=2) {
      if (l%2) {
        ans += tx[l++];
      }
      if (r%2) {
        ans += tx[--r];
      }
    }
    return ans%MOD;
  }
};

struct Segtree {
  //vector<ll> t;
  int n, h;
  Segtree() {}
  Segtree(int sz) {
    h = 32 - __builtin_clz(sz);
    n = 1<<h;
    //t = vector<ll>(n<<1);
  }
  void aset(int x, ll v) {
    t[x+n] = v;
  }
  void build() {
    for (int i=n-1; i; --i) {
      t[i] = t[i<<1]+t[i<<1|1];
    }
  }
  void assign(int x, ll v) {
    x +=n;
    t[x] = v;
    for (x/=2; x; x/=2) {
      t[x] = t[x<<1]+t[x<<1|1];
    }
  }
  
  ll query(int l, int r) {
    ll ans = 0;
    for (l+=n, r+=n; l<r; l/=2, r/=2) {
      if (l%2) {
        ans += t[l++];
      }
      if (r%2) {
        ans += t[--r];
      }
    }
    return ans;
  }

  pair<ll, int> bs(int l, int r, ll goal, int x, int lv, int rv) {
    if (rv<=l || r<=lv) {
      return {0, -1};
    }
    if (l<=lv && rv<=r) {
      if (t[x] < goal) {
        return {t[x], -1};
      }
      if (rv-lv == 1) {
        return {t[x], lv};
      }
    }
    int mv = (lv+rv)/2;
    auto res1 = bs(l, r, goal, x*2, lv, mv);
    if (res1.second != -1) {
      return res1;
    }
    auto res2 = bs(l, r, goal-res1.first, x*2+1, mv, rv);
    return {res2.first+res1.first, res2.second};
  }
  int bs(int l, int r, ll goal) {
    return bs(l, r, goal, 1, 0, n).second;
  }

};

Segtree weights;
SegtreeMOD wx;
int n, q;
ll a[200200];

ll query(int l, int r) {
  ll wtot = weights.query(l, r+1);
  int med = weights.bs(l, r+1, (wtot+1)/2);

  ll ans = ((weights.query(l, med)*2-wtot)%MOD)*a[med] - wx.query(l, med) + wx.query(med, r+1);// - (weights.query(med, r+1)%MOD)*a[med];
  ans = (ans%MOD+MOD)%MOD;
  return ans%MOD;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> q;
  weights = Segtree(n+1);
  wx = SegtreeMOD(n+1);
  for (int i=1; i<=n; ++i) {
    cin >> a[i];
    a[i] -= i;
  }
  for (int i=1; i<=n; ++i) {
    ll w;
    cin >> w;
    weights.aset(i, w);
    wx.aset(i, w*a[i]);
  }
  weights.build();
  wx.build();
  while (q--) {
    int _a, b;
    cin >> _a >> b;
    if (_a > 0) { // query
      cout << query(_a, b) << "\n";
    } else {     // reassign
      int id = -_a, nw = b;
      weights.assign(id, nw);
      wx.assign(id, nw*a[id]);
    }
  }
  return 0;
}