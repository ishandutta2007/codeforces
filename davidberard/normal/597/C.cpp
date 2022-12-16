#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

struct BIT {
  vector<ll> t;
  int n;
  BIT() {}
  BIT(int sz) {
    n = sz;
    t = vector<ll>(n);
  }
  void add(int x, ll v) {
    for (; x<n; x+=x&-x) {
      t[x] += v;
    }
  }
  ll query(int x) {
    ll ans = 0;
    for (; x>0; x-=x&-x) {
      ans += t[x];
    }
    return ans;
  }
  ll query_above(int x) {
    return query(n-1) - query(x-1);
  }
};

const int N = 100100;
ll a[12][N];
BIT b[12];
int v[N];

int n, k;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k;
  for (int i=1; i<=n; ++i) {
    cin >> v[i];
  }
  for (int i=0; i<12; ++i) {
    b[i] = BIT(n+5);
  }
  ll ans = 0;
  for (int i=n; i>=1; --i) {
    for (int j=10; j>=0; --j) {
      ll x = b[j].query_above(v[i]+1);
      b[j+1].add(v[i], x);
      //cerr << " i j (" << i << " " << j << ") : " << x << endl;
      if (j+1 == k) {
        ans += x;
      }
    }
    b[0].add(v[i], 1);
  }
  if (k == 0) {
    ans = n;
  }
  cout << ans << "\n";
  return 0;
}