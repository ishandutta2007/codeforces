#include <bits/stdc++.h>

using namespace std;

int n, k;
int s[100005];

int main() {
  scanf("%d%d", &n, &k);
  int ans = 0;
  for(int i = 0; i<n; i++)
    scanf("%d", s+i), ans = max(ans, s[i]);
  k = min(k, n);
  int off = n-k;
  for(int i = 0; i<off; i++)
    ans = max(ans, s[off+i]+s[off-i-1]);
  cout << ans << endl;

  return 0;
}