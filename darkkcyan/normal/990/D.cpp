#include<bits/stdc++.h>
#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define len(x) ((int)x.size())
using namespace std;

#define maxn 1010

bool m[maxn][maxn] = {0};

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, a, b; cin >> n >> a >> b;
  bool doswap = 0;
  if (a < b) {
    swap(a, b);
    doswap = 1;
  }
  if (b != 1) {
    cout << "NO";
    return 0;
  }
  if (a == 1 and n <= 3 and n != 1) {
    cout << "NO";
    return 0;
  }
  cout << "YES\n";

  rep(i, n - a) {
    m[i][i + 1] = m[i + 1][i] = 1;
  }
  if (doswap) {
    rep(i, n) rep(f, n) if (i != f) m[i][f] = !m[i][f];
  }
  rep(i, n) {
    rep(f, n) 
      cout << m[i][f];
    cout << '\n';
  }
  return 0;
}