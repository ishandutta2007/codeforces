#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 100100;
ll a[N];
int n;

const ll INF = 0x3f3f3f3f3f3f3f3f;

struct Min2 {
  pair<ll, ll> first, second;
  Min2() : first(INF, 0), second(INF, 0) {}
  void insert(pair<ll, ll> x) {
    if (x < first) {
      swap(first, second);
      first = x;
      return;
    }
    if (x < second) {
      second = x;
    }
  }
  ll query(ll s) {
    if (first.second == s) {
      return second.first;
    }
    return first.first;
  }
};

struct Max2 {
  pair<ll, ll> first, second;
  Max2() : first(-INF, 0), second(-INF, 0) {}
  void insert(pair<ll, ll> x) {
    if (x > first) {
      swap(first, second);
      first = x;
      return;
    }
    if (x > second) {
      second = x;
    }
  }
  ll query(ll s) {
    if (first.second == s) {
      return second.first;
    }
    return first.first;
  }
};


int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    cin >> n;
    ll s = 0;
    Min2 lo;
    Max2 hi;
    for (int i=1; i<=n; ++i) {
      cin >> a[i];
      hi.insert({a[i], i});
      lo.insert({a[i], i});
      s += a[i];
    }
    ll ans = 0;
    for (int i=1; i<=n; ++i) {
      ll mn = ((s+n-2)/(n-1));
      mn = max(mn, hi.query(i));
      ans = max(ans, mn*(n-1) - s);
    }
    cout << ans << "\n";
  }
  return 0;
}