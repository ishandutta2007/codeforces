#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long double ld;
typedef vector<pi> vpi;

vi P;

int pare(int x) {
  if (P[x] == -1) return x;
  return P[x] = pare(P[x]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vi S(n, 1);
  P = vi(n, -1);
  int res = k;
  while (k--) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    int px = pare(x);
    int py = pare(y);
    if (px != py) {
      P[px] = py;
      S[py] += S[px];
    }
  }
  for (int i = 0; i < n; ++i) {
    if (P[i] == -1) res -= S[i] -1;
  }
  cout << res << endl;
}