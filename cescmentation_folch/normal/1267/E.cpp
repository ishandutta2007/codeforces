#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n,m;
  cin >> n >> m;
  vvi M(m, vi(n));
  vi V(n,0);
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> M[i][j];
      V[j] += M[i][j];
    }
  }
  int res = n+1;
  vi R;
  for (int i = 0; i < n-1; ++i) {
    int a = V[n-1] - V[i];
    vpi S(m);
    for (int j = 0; j < m; ++j) {
      S[j] = pi(M[j][i] - M[j][n-1], j+1);
    }
    sort(S.begin(), S.end());
    int ind = 0;
    while (a > 0) {
      a += S[ind].first;
      ++ind;
    }
    if (ind < res) {
      res = ind;
      R = vi(ind);
      for (int j = 0; j < ind; ++j) R[j] = S[j].second;
    }
  }
  cout << res << '\n';
  for (int i = 0; i < res; ++i) {
    if (i) cout << ' ';
    cout << R[i];
  }
  cout << '\n';
}