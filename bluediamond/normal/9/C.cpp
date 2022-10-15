#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll n, sol = 0;
  cin >> n;
  queue<ll> q;
  q.push(1);
  while (!q.empty()) {
    sol++;
    ll x = q.front();
    q.pop();
    if (x * 10 <= n) {
      q.push(x * 10);
      if (x * 10 + 1 <= n) {
        q.push(x * 10 + 1);
      }
    }
  }
  cout << sol << "\n";
}