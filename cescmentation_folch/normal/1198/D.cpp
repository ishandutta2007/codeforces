#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

const int N = 50;
int D[N][N][N][N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      char a;
      cin >> a;
      if (a == '#') D[0][0][i][j] = 1;
    }
  }
  for (int d1 = 0; d1 < n; ++d1) { for (int d2 = 0; d2 < n; ++d2) {
    if (d1 == 0 and d2 == 0) continue;
    for (int i = 0; i +d1 < n; ++i) { for (int j = 0; j + d2 < n; ++j) {
      D[d1][d2][i][j] = max(d1+1, d2+1);
      for (int w1 = 0; w1 < d1; ++w1) {
        D[d1][d2][i][j] = min(D[d1][d2][i][j], D[w1][d2][i][j] + D[d1 - w1 -1][d2][i+w1+1][j]);
      }
      for (int w2 = 0; w2 < d2; ++w2) {
        D[d1][d2][i][j] = min(D[d1][d2][i][j], D[d1][w2][i][j] + D[d1][d2 - w2 -1][i][j+w2+1]);
      }
    }}
  }}
  cout << D[n-1][n-1][0][0] << '\n';
}