#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

ll sqr(ll x) {
  return x * x;
}

ll cost(ll x, ll k) {
  if (x % k == 0) {
    return sqr(x / k) * k;
  } else {
    ll a = x / k;
    return sqr(a) * (k - x % k) + sqr(a + 1) * (x % k);
  }
}

struct T {
  int x;
  int k;
  ll cur;
  ll nxt;
};

bool operator < (T a, T b) {
  return a.cur - a.nxt < b.cur - b.nxt;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  priority_queue<T> q;
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    q.push({x, 1, cost(x, 1), cost(x, 2)});
  }
  for (int i = n + 1; i <= k; i++) {
    auto it = q.top();
    q.pop();
    it.k++;
    it.cur = cost(it.x, it.k);
    it.nxt = cost(it.x, it.k + 1);
    q.push(it);
  }
  ll sol = 0;
  while (!q.empty()) {
    sol += q.top().cur;
    q.pop();
  }
  cout << sol << "\n";
}