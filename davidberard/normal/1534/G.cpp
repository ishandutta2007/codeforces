#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

struct Lines {
  priority_queue<ll, vector<ll>, greater<ll>> upper;
  priority_queue<ll> lower;
  ll m=0, b=0;
  void insert(ll x, ll off) {
    ll lbound = (lower.empty() ? -1e18 : lower.top()+off);
    ll rbound = (upper.empty() ?  1e18 : upper.top());
    if (x < lbound) {
      lower.push(x-off);
    } else {
      upper.push(x);
    }
    if (x <= rbound) {
      lower.push(x-off);
    } else {
      upper.push(x);
    }
    if (lower.size() > upper.size()) {
      upper.push(lower.top()+off); lower.pop();
    }
    if (lower.size() < upper.size()) {
      lower.push(upper.top()-off); upper.pop();
    }
    m++;
    b -= x;
  }
  ll calc(ll x) {
    vector<ll> up, lp;
    while (!upper.empty()) {
      up.push_back(upper.top()); upper.pop();
    }
    while (!lower.empty()) {
      lp.push_back(lower.top()); lower.pop();
    }
    reverse(lp.begin(), lp.end());
    lp.insert(lp.end(), up.begin(), up.end());
    while (!lp.empty() && lp.back() > x) {
      b += lp.back();
      --m;
      lp.pop_back();
    }
    return m*x + b;
  }
};

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  vector<pair<ll, ll>> vec(n);
  for (auto& [x, y] : vec) {
    cin >> x >> y;
  }
  sort(vec.begin(), vec.end(), [](const pair<ll, ll>& a, const pair<ll, ll>& b) {
    return a.first+a.second > b.first+b.second;
  });
  Lines lines;
  for (auto& [x, y] : vec) {
    lines.insert(x, x+y);
  }
  cout << lines.calc(0) << "\n";
  return 0;
}