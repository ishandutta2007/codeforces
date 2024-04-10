#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using cd = complex<ld>;

map<ll, pair<ll, ll>> dp;

pair<ll, ll> slow_solve(ll x) {
  if (x == 0) {
    return {0, 0};
  }
  if (dp.count(x)) {
    return dp[x];
  }
  pair<ll, ll> ans = slow_solve(x - 1);
  swap(ans.first, ans.second);
  ans.first++;
  if (x % 2 == 0) {
    auto p = slow_solve(x / 2);
    swap(p.first, p.second);
    p.first += x / 2;
    ans = max(ans, p);
  }
  return dp[x] = ans;
}

pair<ll, ll> solve(ll x) {
  if (x == 0) {
    return {0, 0};
  }
  if (x == 4) {
    return {3, 1};
  }
  if (x % 2 == 1) {
    auto p = solve(x - 1);
    swap(p.first, p.second);
    p.first++;
    return p;
  } else if ((x % 4 != 0)) {
    auto p = solve(x / 2);
    swap(p.first, p.second);
    p.first += x / 2;
    return p;
  } else {
    auto a = solve(x - 2);
    a.first += 1;
    a.second += 1;
    return a;
  }
}

void stress() {
  for (int i = 1; i <= 100; i++) {
    cout << i << " " << solve(i).first << " " << slow_solve(i).first << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

//  stress();

  int test;
  cin >> test;
  while (test--) {
    ll x;
    cin >> x;
    cout << solve(x).first << "\n";
  }

  return 0;
}