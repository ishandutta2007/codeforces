#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

#define bt(x,y) !!(x&(1<<y))

const int N = 22;
int amt[N*2];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n, x, y;
  cin >> n >> x >> y;
  for (int i=0; i<x+y; ++i) {
    amt[i] = (n+x+y-i-1)/(x+y);
  }
  int z = max(x, y);
  int w = min(x, y);
  int ans = 0;
  for (int i=0; i<(1<<z); ++i) {
    int cur = 0;
    for (int j=0; j<z; ++j) {
      if (i&(1<<j)) {
        cur += amt[j+w];
      }
      if (bt(i,j) && ((j+x<z && bt(i,j+x)) || (j+y<z && bt(i,j+y)))) {
        cur = -1.1e9;
      }
    }
    for (int j=0; j<w; ++j) {
      if (bt(i,j+x-w) || bt(i,j+y-w)) {
        continue;
      } else {
        cur += amt[j];
      }
    }
    ans = max(ans, cur);
  }
  cout << ans << "\n";
  return 0;
}