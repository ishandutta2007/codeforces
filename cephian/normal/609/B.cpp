#include <iostream>

using namespace std;

int g[15];

int main() {
  ios::sync_with_stdio(0);
  int n, m;
  int ans = 0;
  cin >> n >> m;
  for(int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    ++g[t];
  }
  for(int i = 1; i <= m; ++i) {
    for(int j = i+1; j <= m; ++j) {
      ans += g[i]*g[j];
    }
  }
  cout << ans << "\n";

  return 0;
}