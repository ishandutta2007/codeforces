#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = (ll) 1e18 + 7;

ll computeBring(int dist, int p) {
  assert(0 <= p && p < (1 << (dist - 1)));
  if (dist == 1) {
    assert(p == 0);
    return 1;
  }
  if (p < (1 << (dist - 2))) {
    return 1 + computeBring(dist - 1, p);
  } else {
    return (1LL << ((dist - 1))) + computeBring(dist - 1, p - (1LL << (dist - 2)));
  }
}

ll cnt_bits(int p) {
  int sol = 0;
  while (p > 0) {
    sol += p % 2;
    p /= 2;
  }
  return sol;
}

ll solve(int x, ll need, vector<ll> cnt) {
  int n = (int) cnt.size();
  assert(0 <= x && x < n);
  {
    ll sum = 0;
    for (int i = 0; i < n; i++) {
      sum += (1LL << i) * cnt[i];
    }
    if (sum < need) {
      return -1;
    }
  }
  for (int i = 0; i <= x; i++) {
    need -= cnt[i];
  }
  if (need <= 0) {
    return 0;
  }

  ll cost = 0;
  ///cout << need << ": " << cost << "\n";
  for (int i = x + 1; i < n; i++) {
  ///for (int i = n - 1; i > x; i--) {
    ll gain = (1LL << (i - x));
    ll cnt_steps = (1LL << (i - x)) - 1;
    ll take = min(cnt[i], need / gain);
    cnt[i] -= take;
    cnt[x] += gain * take;
    need -= take * gain;
    cost += take * cnt_steps;
  }
  ll max_extra = 0;
  for (int i = 0; i <= x; i++) {
    max_extra += ((1LL << i) - 1) * cnt[i];
  }
  if (need <= max_extra) {
    return cost + need;
  } else {
    assert(max_extra < need);
    /// aduc x
    /// => need -=
    ll press = 0;

    while (max_extra + ((1LL << x) - 1) * 2 * press < need - 2 * press) {
      press++;
    }
    ///cout << "need = " << need << ", max_extra = " << max_extra << "\n";
    ll extra = 0;
    ll print = -INF;
    bool f = 0;
    for (int i = x + 1; i < n; i++) {
      if (cnt[i]) {
        ll A = (1LL << (x + 1));
        ll B = need - max_extra;
        ll start = (B + A - 1) / A;
        ll L = start;
        ll R = min(need / 2, (1LL << (i - x - 1)));

        L--;
        R--;

        ll putere = 0;
        while ((1LL << (putere + 1)) - 1 <= R) {
          putere++;
        }


        const ll limit = 200;

        if (L <= R) {
          if (L <= (1LL << putere) - 1) {
            print = putere;
          } else {
            if (L == R) {
              print = cnt_bits(L);
            } else {
              int com = 0;
              for (int i = 30; i >= 0; i--) {
                bool is_l = !!(L & (1 << i));
                bool is_r = !!(R & (1 << i));
                if (is_l != is_r) {
                  print = i + com;

                  break;
                } else {
                  com += is_l;
                }
              }
            }
          }
        }

        ll dist = i - x;
        print = dist - 2 - print;
        print += need;
        if (need / 2 + 1 <= 1LL << (i - x - 1)) {
          ll press = need / 2 + 1;
          print = min(print, computeBring(i - x, press - 1) + max(0LL, need - 2 * press));
        }
        print += cost;
        break;
      }
    }
    return print;
  }


  exit(0);
  assert(need >= 0);
  if (need == 0) {
    return cost;
  }
  return (ll) 1e18 + cost;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE


  int print = 0;

  int n, q;
  cin >> n >> q;
  vector<ll> cnt(n);
  for (int i = 0; i < n; i++) {
    cin >> cnt[i];
  }
  vector<ll> init = cnt;
  vector<ll> want = {1, 6, 1, 10, 6, 10, 10, 10, 8, 1, 3, 3, 3, 9, 3, 6, 8, 3, 1, 1, 6, 3, 5, 0, 9, 0, 4, 2, 5, 9};
  for (int iq = 0; iq < q; iq++) {
    int type;
    cin >> type;
    assert(type == 1 || type == 2);
    if (type == 1) {
      int pos, val;
      cin >> pos >> val;
      cnt[pos] = val;
      continue;
    }
    assert(type == 2);
    int x;
    ll k;
    cin >> x >> k;
    print++;
    if (init == want && 0) {
      if (print == 89426) {
        cout << n << " 1\n";
        for (int i = 0; i < n; i++) {
          cout << cnt[i] << " ";
        }
        cout << "\n";
        cout << "2 " << x << " " << k << "\n";
        cout << "\n\n";
        cout << solve(x, k, cnt) << "\n";
      }
      continue;
    }
    cout << solve(x, k, cnt) << "\n";
  //  cout << solve(x, k, cnt) << "\n";
  //  cout << print << " : " << solve(x, k, cnt) << "\n";
  }
}