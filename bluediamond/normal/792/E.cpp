#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll INF = (ll) 1e18;
const int N = 500 + 7;
int n;
int a[N];
ll best = INF;
vector<int> s;

ll f(ll a, ll x) {
  ll k = (a + x) / (x + 1);
  if (k * x <= a) {
    return k;
  } else {
    return INF;
  }
}

void upd(ll x) {
  ll sol = 0;
  for (int i = 1; i <= n; i++) {
    sol += f(a[i], x);
    if (sol >= best) {
      return;
    }
  }
  best = sol;
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  for (int x = 1; x * x <= a[1]; x++) {
    s.push_back(x);
  }
  for (int k = 1; k * k <= a[1]; k++) {
    int l = (a[1] + k - 1) / k - 1;
    int r = a[1] / k;
    for (int j = l; j <= r; j++) {
      s.push_back(j);
    }
  }
  sort(s.rbegin(), s.rend());
  for (int i = 0; i < (int) s.size() && best == INF; i++) {
    if (i == 0 || s[i] != s[i - 1]) {
      upd(s[i]);
    }
  }
  cout << best << "\n";
}