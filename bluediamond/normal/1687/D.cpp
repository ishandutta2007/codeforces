#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

mt19937 rng((long long) (new char));

ll get_radical(ll x) {
  return sqrt(x);

}

bool isok(ll x) {
  ll r = get_radical(x);
  return r * r <= x && x <= r * r + r;
}

ll get_next_ok(ll x) {
  ll r = get_radical(x);
  if (r * r <= x && x <= r * r + r) {
    return x;
  } else {
    return (r + 1) * (r + 1);
  }
}

ll get_ant_ok(ll x) {
  ll r = get_radical(x);
  if (r * r <= x && x <= r * r + r) {
    return x;
  } else {
    return r * r + r;
  }
}

const int N = (int) 1e6 + 7;
int n;
ll a[N];

signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

  if (0) {
    for (int x = 1; x <= 10; x++) {
      int l = x * x, r = (x + 1) * (x + 1) - 1;
      vector<int> v;
      for (int i = l; i <= r; i++) {
        if (isok(i)) {
          v.push_back(i);
        }
      }
      cout << x << " : " << (int) v.size() << " ----> ";
      for (auto &x : v) {
        cout << x << " ";
      }
      cout << "\n";
    }
  }

  cin >> n;
  for (int i = 1; i <= n; i++) {
    int foo;
    cin >> foo;
    a[i] = foo;
  }

  shuffle(a + 2, a + n + 1, rng);
  for (ll what1 = 1; 1; what1++) {

    ll l_add = what1 * what1;
    ll r_add = what1 * what1 + what1;
    if (r_add < a[1]) continue;
    l_add -= a[1];
    r_add -= a[1];
    l_add = max(l_add, 0LL);
    assert(l_add <= r_add);
    for (int i = 1; i <= n; i++) {
      assert(l_add <= r_add);
      /// caut pe cineva bun in intervalul asta


      ll mn = a[i] + l_add, mx = a[i] + r_add;
      mn = get_next_ok(mn);
      mx = get_ant_ok(mx);


      mn -= a[i];
      mx -= a[i];

      l_add = mn;
      r_add = mx;
      if (l_add > r_add) {
        shuffle(a + 2, a + i + 1, rng);
        break;
      }
    }
    if (l_add > r_add) continue;

    cout << l_add << "\n";
    return 0;
  }
  assert(0);
}