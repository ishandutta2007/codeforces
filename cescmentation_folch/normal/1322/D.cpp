#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

void debug(vvi A, int val) {
  cerr << " val = " << val << endl;
  cerr << endl;
  cerr << "---- DEBUG ----" << endl;
  for (auto v : A) {
    for (auto x : v) cerr << x << ' ';
    cerr << endl;
  }
  cerr << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vpi V(n);
  for (int i = 0; i < n; ++i) cin >> V[i].first;
  for (int i = 0; i < n; ++i) cin >> V[i].second;
  vi A(n+m+1,0);
  for (int i = 1; i<= n+m; ++i) cin >> A[i];
  reverse(V.begin(), V.end());
  int INF = 1000000000;
  vvi D(n+m+1, vi(n+1, -INF));
  for (int i = 1; i <= n+m; ++i) D[i][0] = 0;
  for (auto it : V) {
    for (int g = n; g >= 1; --g) {
      if (D[it.first][g-1] == -INF) continue;
      D[it.first][g] = max(D[it.first][g], D[it.first][g-1] + A[it.first] - it.second);
    }
    int val = n;
    for (int k = it.first+1; k <= n+m; ++k) {
      for (int g = 0; g <= val; ++g) {
        if (D[k-1][g] == -INF) continue;
        D[k][g/2] = max(D[k-1][g] + (g/2)*A[k], D[k][g/2]);
      }
      val /= 2;
    }
  }
  cout << D[n+m][0] << '\n';
}