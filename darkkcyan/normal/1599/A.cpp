#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using cd = complex<ld>;

const int maxn = 201010;
int n;
int a[maxn];
string s;

int chsign(char ch) {
  return ch == 'L' ? 1 : -1;
}

int sign(ll x) {
  return x < 0 ? -1 : x > 0;
}

vector<int> solve() {
  sort(a, a + n, greater<int>());

  vector<int> moments = {0};
  for (int i = 1; i < n; ++i) {
    if (s[i] != s[i - 1]) moments.push_back(i);
  }

  int k = (int)moments.size();
  reverse(a, a + k);
  ll bal = chsign(s[0]) * a[0];
  vector<int> ans = {(int)bal};
  int u = 1, v = k;
  for (int i = 1; i < n; ++i) {
    if (s[i] != s[i - 1]) {
      ll x =  chsign(s[i]) * a[u ++];
      bal += x;
      ans.push_back((int)x);
    } else {
      ll nb = bal - chsign(s[i]) * a[v];
      ans.push_back(-chsign(s[i]) * a[v]);
      if (sign(nb) != chsign(s[i])) {
        nb = bal + chsign(s[i]) * a[v];
        ans.back() *= -1;
      }
      bal = nb;
      ++v;
    }
    if (sign(bal) != chsign(s[i])) return {};
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  cin >> s;
  auto ans = solve();
  if (ans.size()) {
    for (auto i: ans) {
      cout << abs(i) << ' ';
      if (i > 0) cout << 'L';
      else cout << 'R';
      cout << '\n';
    }
  } else {
    cout << "-1";
  }

  return 0;
}