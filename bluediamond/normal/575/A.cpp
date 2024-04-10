#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll MOD;

struct M12 {
  ll x00 = 0, x01 = 0;
};

struct M22 {
  ll x00 = 0, x01 = 0;
  ll x10 = 0, x11 = 0;
};

M22 operator * (M22 a, M22 b) {
  M22 c;
  c.x00 = (1LL * a.x00 * b.x00 + 1LL * a.x01 * b.x10) % MOD;
  c.x01 = (1LL * a.x00 * b.x01 + 1LL * a.x01 * b.x11) % MOD;
  c.x10 = (1LL * a.x10 * b.x00 + 1LL * a.x11 * b.x10) % MOD;
  c.x11 = (1LL * a.x10 * b.x01 + 1LL * a.x11 * b.x11) % MOD;
  return c;
}

M12 operator * (M12 a, M22 b) {
  M12 c;
  c.x00 = (1LL * a.x00 * b.x00 + 1LL * a.x01 * b.x10) % MOD;
  c.x01 = (1LL * a.x00 * b.x01 + 1LL * a.x01 * b.x11) % MOD;
  return c;
}

M22 operator ^ (M22 a, ll b) {
  M22 r;
  r.x00 = r.x11 = 1;
  while (b) {
    if (b & 1) {
      r = r * a;
    }
    a = a * a;
    b /= 2;
  }
  return r;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen ("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  ll k;
  cin >> k >> MOD;

  if (k == 0 || MOD == 1) {
    cout << "0\n";
    exit(0);
  }

  ll n;
  vector<ll> s;
  cin >> n;
  s.resize(n);
  for (auto &c : s) {
    cin >> c;
    c %= MOD;
  }

  ll cnt_spec;
  vector<pair<ll, ll>> special;
  map<ll, ll> special_map;
  cin >> cnt_spec;
  special.resize(cnt_spec);
  for (auto &it : special) {
    cin >> it.first >> it.second;
    it.second %= MOD;
    special_map[it.first] = it.second;
  }
  sort(special.begin(), special.end());

  vector<M22> tree(4 * (n + 7));

  function<void(ll, ll, ll)> build_tree = [&] (ll v, ll tl, ll tr) {
    if (tl < tr) {
      ll tm = (tl + tr) / 2;
      build_tree(2 * v, tl, tm);
      build_tree(2 * v + 1, tm + 1, tr);
      tree[v] = tree[2 * v] * tree[2 * v + 1];
      return;
    }
    tree[v].x00 = 0;
    tree[v].x10 = 1;

    tree[v].x01 = s[(tl + n - 1) % n];
    tree[v].x11 = s[tl];
  };

  function<M22(ll, ll, ll, ll, ll)> get_tree = [&] (ll v, ll tl, ll tr, ll l, ll r) {
    if (tr < l || r < tl) {
      M22 mlt;
      mlt.x00 = mlt.x11 = 1;
      return mlt;
    }
    if (l <= tl && tr <= r) {
      return tree[v];
    }
    ll tm = (tl + tr) / 2;
    return get_tree(2 * v, tl, tm, l, r) * get_tree(2 * v + 1, tm + 1, tr, l, r);
  };

  function<M22(ll, ll)> get = [&] (ll l, ll r) {
    return get_tree(1, 0, n - 1, l, r);
  };

  build_tree(1, 0, n - 1);

  function<ll(ll)> get_coef = [&](ll x) {
    if (special_map.count(x)) {
      return special_map[x];
    } else {
      return s[x % n];
    }
  };

  function<M22(ll)> getM22 = [&] (ll i) {
    M22 mlt;
    mlt.x00 = 0;
    mlt.x10 = 1;

    mlt.x01 = get_coef(i - 1);
    mlt.x11 = get_coef(i);

    return mlt;
  };

  M22 all;
  all.x00 = all.x11 = 1;
  all = all * getM22(n);
  for (ll i = 1; i < n; i++) {
    all = all * getM22(i);
  }

  function<M22(ll, ll)> getM22llerval = [&] (ll l, ll r) {
    assert(l <= r);
    M22 current;
    current.x00 = 1;
    current.x11 = 1;

    if (r - l + 1 <= n) {
      assert(l + n > r);
      if (l % n <= r % n) {
        return get(l % n, r % n);
      }
      assert(l % n > r % n);
    }

    if (l % n != 0) {
      current = current * get(l % n, n - 1);
      l = l + n - l % n;
    }

    M22 memo;
    memo.x00 = memo.x11 = 1;

    if (r % n != n - 1) {
      memo = memo * get(0, r % n);
      r = r - r % n - 1;
    }

    assert(l % n == 0);
    assert(r % n == n - 1);

    assert(r - l + 1 >= 0);
    assert((r - l + 1) % n == 0);

    current = current * (get(0, n - 1) ^ ((r - l + 1) / n));

    current = current * memo;
    return current;
  };

  M12 current;
  current.x00 = 0;
  current.x01 = 1;

  k--;

  if (1) {
    ll last_done = 0;
    for (ll iter = 0; iter < (ll) special.size(); iter++) {
      ll i = special[iter].first;
      ll until = min(k, i - 4);

      if (last_done + 1 <= until) {
        current = current * getM22llerval(last_done + 1, until);
        last_done = until;
      }


      until = min(k, i + 4);
      while (last_done < until) {
        current = current * getM22(++last_done);
      }
    }
    ll until = k;
    if (last_done + 1 <= until) {
      current = current * getM22llerval(last_done + 1, until);
      last_done = until;
    }

  } else {
    for (ll i = 1; i <= k; i++) {
      current = current * getM22(i);
    }
  }
  cout << current.x01 << "\n";

#ifndef ONLINE_JUDGE
  assert(current.x01 == 7925);
#endif // ONLINE_JUDGE

  exit(0);
  if (0) {
    ll n1 = 1;
    ll m1 = 2;
    ll n2 = 2;
    ll m2 = 2;

    assert(m1 == n2);

    for (ll i = 0; i < n1; i++) {
      for (ll j = 0; j < m2; j++) {
        cout << "c.x" << i << j << " = (";
        for (ll k = 0; k < m1; k++) {
          cout << "1LL * a.x" << i << k << " * b.x" << k << j;
          if (k + 1 < m1) {
            cout << " + ";
          }
        }
        cout << ") % MOD;\n";
      }
    }
  }

  return 0;
}