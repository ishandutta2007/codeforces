#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int n, val[N];
pair< int, int > b[N];

int main() {
  scanf("%d", &n);
  for(int i = 0; i<n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    b[i] = {x, y};
  }
  sort(b, b+n);
  int ans = n-1;
  val[0] = 0;
  for(int i = 1; i<n; i++) {
    int p = upper_bound(b, b+n, make_pair(b[i].first-b[i].second, 0))-b-1;
    if(p < 0)
      val[i] = i;
    else
      val[i] = val[p] + i-p-1;
    ans = min(ans, val[i]+n-i-1);
  }
  cout << ans << endl;
  return 0;
}