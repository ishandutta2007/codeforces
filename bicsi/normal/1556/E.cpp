#include <bits/stdc++.h>

using namespace std;

struct ll {
  long long sum = 0, minsum = 0, maxsum = 0;
  ll(int x = 0) : sum(x), minsum(x), maxsum(x) {}

  ll operator+(const ll& oth) const {
    ll ret = *this;
    ret.minsum = min(ret.minsum, ret.sum + oth.minsum);
    ret.maxsum = max(ret.maxsum, ret.sum + oth.maxsum);
    ret.sum = ret.sum + oth.sum;
    return ret;
  }
};
ostream& operator<<(ostream& cout, ll res) {
  cout << "(" << res.sum << " " << res.minsum << " " << res.maxsum << ")";
  return cout;
}

struct SegTree {
  vector<ll> T; int n;
  SegTree(int n) : T(2 * n), n(n) {}

  void Update(int p, ll val) {
    for (T[p += n] = val; p >>= 1; ) 
      T[p] = T[p * 2] + T[p * 2 + 1];
  }
  ll Query(int b, int e) {
    ll l, r;
    for (b += n, e += n; b < e; b /= 2, e /= 2) {
      if (b % 2) l = l + T[b++];
      if (e % 2) r = T[--e] + r;
    }
    //cerr << l << " " << r << " " << l + r << endl;
    return l + r;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int n, q; cin >> n >> q;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  SegTree T(n);
  for (int i = 0; i < n; ++i) {
    //cerr << b[i] - a[i] << " ";
    T.Update(i, ll(b[i] - a[i]));
  }
  //cerr << endl;
  
  for (int i = 0; i < q; ++i) {
    int l, r; cin >> l >> r;
    /*
    ll bla;
    for (int i = l - 1; i < r; ++i)
      bla = bla + ll(b[i] - a[i]);
    */
    auto res = T.Query(l - 1, r);
    //cerr << "bla = " << bla << endl;

    if (res.sum != 0 || res.minsum < 0) {
      cout << -1 << '\n';
    } else {
      cout << res.maxsum << '\n';
    }
  }
  return 0;
}