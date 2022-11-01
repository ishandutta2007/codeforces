#include <bits/stdc++.h>

using namespace std;

int main() {
  map< int, int > a, b;
  int n;
  scanf("%d", &n);
  for(int i = 0; i<n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    a[x+y]++;
    b[x-y]++;
  }
  long long ans = 0;
  for(auto it = a.begin(); it != a.end(); it++) {
    ans += 1LL*(it->second - 1) * (it->second);
  }
  for(auto it = b.begin(); it != b.end(); it++) {
    ans += 1LL*(it->second - 1) * (it->second);
  }
  ans /= 2;
  cout << ans << endl;
  return 0;
}