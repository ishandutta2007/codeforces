#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = (int) 2e5 + 7;
ll fact[16];
int n;
int q;
int a[N];
int from;

ll gauss(ll i) {
  return i * (i + 1) / 2;
}

ll get(int i) {
  ll sol = 0;
  if (i < from) {
    return gauss(i);
  } else {
    ll sol = gauss(from - 1);
    for (int j = from; j <= i; j++) {
      sol += a[j];
    }
    return sol;
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  fact[0] = 1;
  for (ll i = 1; i < 16; i++) {
    fact[i] = fact[i - 1] * i;
  }

  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    a[i] = i;
  }
  if (n >= 14) {
    from = n - 14;
  } else {
    from = 1;
  }
  ll S = 0;
  for (int i = 1; i <= q; i++) {
    int type;
    cin >> type;
    if (type == 1) {
      int l, r;
      cin >> l >> r;
      cout << get(r) - get(l - 1) << "\n";
      continue;
    }
    int x;
    cin >> x;
    S += x;
    vector<int> free_elems;
    for (int i = from; i <= n; i++) {
      free_elems.push_back(i);
    }
    ll cur = S;
    for (int i = from; i <= n; i++) {
      ll coef = fact[n - i];
      ll id = cur / coef;
      cur %= coef;
      a[i] = free_elems[id];
      for (int j = id; j < (int) free_elems.size() - 1; j++) {
        free_elems[j] = free_elems[j + 1];
      }
      free_elems.pop_back();
    }
    continue;
  }




  return 0;
}