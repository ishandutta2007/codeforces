#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
typedef long double ld;
bool home = 1;

mt19937 rng((long long) (new char));
ll tr[26];

const int N = (int) 3e5 + 7;
ll put[N];

ll gethash(string s) {
  ll sol = 0;
  for (int i = 0; i < (int) s.size(); i++) {
    sol += put[i] * tr[s[i] - 'a'];
  }
  return sol;
}

set<ll> active[N];

ll isprime(ll x) {
  if (x <= 1) return 0;
  for (ll i = 2; i * i <= x && i <= (ll) 1e6; i++) {
    if (x % i == 0) return 0;
  }
  return 1;
}

signed main() {
  ///ios::sync_with_stdio(0); cin.tie(0);

  #ifdef ONLINE_JUDGE
  home = 0;
  #endif // ONLINE_JUDGE


  if (home) {
    freopen ("input", "r", stdin);
  }


  while (1) {
    set<ll> s;
    for (int i = 0; i < 26; i++) {
      tr[i] = (ll) rng() * rng() + rng();
      while (!isprime(tr[i])) tr[i]++;
      s.insert(tr[i]);
    }
    if ((int) s.size() == 26) break;
  }

  ll mx = 0;
  for (int i = 0; i < 26; i++) {
    mx = max(mx, tr[i]);
  }

  while (1) {

    put[0] = 1;
    put[1] = mx + rng();
    while (!isprime(put[1])) put[1]++;

    for (int i = 2; i < N; i++) {
      put[i] = put[i - 1] * put[1];
    }

    set<ll> s;
    for (int i = 0; i < N; i++) {
      s.insert(put[i]);
    }

    if ((int) s.size() == N) break;

  }

  set<int> lengths;
  string first;
  int q;
  cin >> q;
  for (int iq = 1; iq <= q; iq++) {
    int type;
    string s;
    cin >> type >> s;
    if (type == 1) {
      lengths.insert((int) s.size());
      active[(int) s.size()].insert(gethash(s) + tr[s[0] - 'a']);
      continue;
    }
    if (type == 2) {
      active[(int) s.size()].erase(gethash(s) + tr[s[0] - 'a']);
      continue;
    }
    if (type == 3) {
      int n = (int) s.size();
      int sol = 0;
      for (auto &l : lengths) {
        if (l > n) continue;

        ll cur = 0;
        for (int j = 0; j < l; j++) {
          cur += put[j] * tr[s[n - l + j] - 'a'];
        }
        sol += active[l].count(cur + tr[s[n - l] - 'a']);
        for (int i = n - l - 1; i >= 0; i--) {
          cur -= put[l - 1] * tr[s[i + l] - 'a'];
          cur *= put[1];
          cur += tr[s[i] - 'a'];
          sol += active[l].count(cur + tr[s[i] - 'a']);
        }
      }
      cout << sol << endl;
      continue;
    }
    assert(0);
  }

  return 0;
}
/**



**/