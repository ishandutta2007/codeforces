#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ld, ld> pld;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
typedef vector<ld> vld;
typedef vector<vld> vvld;
typedef vector<pld> vpld;
typedef vector<vpld> vvpld;

int main() {
  ll INF = 1e11;
  int n;
  cin >> n;
  vi P(n, 0);
  for (int i = 1; i < n; ++i) {
    cin >> P[i];
    --P[i];
  }
  vi V(n);
  for (int i = 0; i < n; ++i) cin >> V[i];
  vi S = V;
  for (int i = 0; i < n; ++i) {
    if (S[i] == -1) S[i] = INF;
  }
  for (int i = n -1; i > 0; --i) {
    S[P[i]] = min(S[P[i]], S[i]);
  }
  ll res = S[0];
  for (int i = n -1; i >= 0; --i) {
    if (S[i] == INF) S[i] = S[P[i]];
    if (S[i] < V[i]) {
      cout << -1 << '\n';
      return 0;
    }
    res += S[i] - S[P[i]];
  }
  cout << res <<'\n';
}