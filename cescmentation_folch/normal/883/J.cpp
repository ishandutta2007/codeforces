#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;
typedef vector<ll> vi;
const ll N = 100010;

pi D[N];
ll A[N];
vi P[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll n, m;
  cin >> n >> m;
  for (ll i = 0; i < n; ++i) cin >> A[i];
  for (ll i = 0; i < m; ++i) cin >> D[i].first;
  for (ll i = 0; i < m; ++i) cin >> D[i].second;
  sort(D, D + m);
  ll j1 = 0;
  for (ll i = n - 1; i >= 0; --i) {
    while (j1 < m and D[j1].first <= A[i]) {
      P[i].push_back(j1);
      ++j1;
    }
  }
  ll sum = 0;
  ll preu = 0;
  priority_queue<ll> Q;
  for (int i = 0; i < n; ++i) {
    preu += A[i];
    for (int j = 0; j < (int)P[i].size(); ++j) {
      sum += D[P[i][j]].second;
      Q.push(D[P[i][j]].second);
    }
    while (sum > preu) {
      sum -= Q.top();
      Q.pop();
    }
  }
  cout << Q.size() << endl;
}