#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 2e5 + 7;
int n;
ll want, a[N];

void update() {
  reverse(a + 1, a + n + 1);
  while (n && a[n] == 0) {
    n--;
  }
  reverse(a + 1, a + n + 1);
}

const ll INF = (ll) 2e18 + 7;

ll mult(ll a, ll b) {
  if (a == 0 || b == 0) {
    return 0;
  }
  if (a == INF || b == INF) {
    return INF;
  }
  ll p = a * b;
  if (p % a == 0 && p / a == b && p <= INF) {
    return p;
  } else {
    return INF;
  }
}

ll add(ll a, ll b) {
  return min(a + b, INF);
}

ll eval(ll x, ll y, ll z, ll i) {
  ll ans = z;
  ans = add(ans, mult(y, i));
  ll cx = i * (i + 1) / 2;
  ans = add(ans, mult(x, cx));
  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> want;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] >= want) {
      cout << "0\n";
      return 0;
    }
  }
  update();
  if (n == 2) {
    ll x = a[1];
    ll y = a[2];
    ll i = (want - y + x - 1) / x;
    cout << i << "\n";
    return 0;
  }
  if (n == 3) {
    ll x = a[1];
    ll y = a[2];
    ll z = a[3];
    ll lo = 0, hi = (ll) 2e9, ans;
    while (lo <= hi) {
      ll mid = (lo + hi) / 2;
      if (eval(x, y, z, mid) >= want) {
        ans = mid;
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }
    cout << ans << "\n";
    return 0;
  }
  ll ans = 0;
  while (1) {
    ans++;
    for (int i = 1; i <= n; i++) {
      a[i] += a[i - 1];
      if (a[i] >= want) {
        cout << ans << "\n";
        return 0;
      }
    }
  }
}