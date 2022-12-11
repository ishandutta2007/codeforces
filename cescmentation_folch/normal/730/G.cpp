#include <iostream>
#include <vector>
#include <set>
using namespace std;
using ll = long long;
using PLL = pair<ll, ll>;
using VPLL = vector<PLL>;
#define X first
#define Y second

struct T {
  ll x, y, i;
  T(ll x, ll y, ll i) : x(x), y(y), i(i) {}
};
bool operator<(const T& a, const T& other) {
  if (a.x < other.x) return true;
  if (a.x > other.x) return false;
  if (a.y < other.y) return true;
  if (a.y > other.y) return false;
  return a.i < other.i;
}
using S = set<T>;

bool bet(ll x, ll l, ll r) {
  return x >= l && x <= r;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n; cin >> n;
  S v;
  for (int i = 0; i < n; ++i) {
    ll start, d; cin >> start >> d;
    ll end = start + d - 1;
    bool pos = true;
    for (auto p : v) {
      if (bet(start, p.x, p.y) ||
          bet(end, p.x, p.y) ||
          bet(p.x, start, end) ||
          bet(p.y, start, end)) {
        pos = false;
        break;
      }
    }
    if (pos) {
      v.insert({start, end, i});
    } else {
      ll st = 1;
      for (auto p : v) {
        if (p.x > st + d-1) {
          break;
        } 
        st = p.y + 1;
      }
      v.insert({st, st+d-1, i});

    }
  }
  VPLL ans(n);
  for (auto t : v) {
    ans[t.i] = {t.x, t.y};
  }
  for (auto p : ans) {
    cout << p.X << " " << p.Y << endl;
  }





}