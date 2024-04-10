#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pi;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vpi A(n);
  for (int i = 0; i < n; ++i) cin >> A[i].first;
  for (int i = 0; i < n; ++i) cin >> A[i].second;
  sort(A.begin(), A.end());
  ll res = 0;
  ll acu = 0;
  priority_queue<ll> Q;
  ll val = -1;
  for (int i = 0; i < n; ++i) {
    while (val < A[i].first and !Q.empty()) {
      ll k = Q.top(); Q.pop();
      acu -= k;
      res += acu;
      ++val;
    }
    val = A[i].first;
    acu += A[i].second;
    Q.push(A[i].second);
  }
  while (!Q.empty()) {
    ll k = Q.top(); Q.pop();
    acu -= k;
    res += acu;
  }
  cout << res <<'\n';
}