#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = (int) 1e6 + 7;
int n;
vector<pair<int, ll>> sol;

pair<int, ll> operator + (pair<int, ll> a, pair<int, ll> b) {
  a.first += b.first;
  a.second += b.second;
  return a;
}

bool take(pair<int, ll> a, pair<int, ll> b) {
  b = a + b;
  return a.second * (ll) b.first > b.second * (ll) a.first;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    pair<int, ll> cur = {1, x};
    while (!sol.empty() && take(sol.back(), cur)) {
      cur = sol.back() + cur;
      sol.pop_back();
    }
    sol.push_back(cur);
  }
  for (auto &it : sol) {
    for (int i = 1; i <= it.first; i++) {
      cout << fixed << setprecision(9) << (ld) it.second / it.first << "\n";
    }
  }
}