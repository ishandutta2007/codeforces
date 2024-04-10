#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5; 

char a[N], b[N];
int cnt[N], n, m;

int main() {
  scanf("%s%s", a, b);
  n = strlen(a);
  m = strlen(b);
  for(int i = 0; i<n; i++)
    cnt[i+1] = cnt[i] + (a[i] == '1');
  long long ans = 0;
  for(int i = 0; i<m; i++) {
    int l = max(0, n-m+i), r = min(n, i+1);
    if(b[i] == '0')
      ans += cnt[r]-cnt[l];
    else
      ans += r-l - (cnt[r]-cnt[l]);
  }
  cout << ans << endl;

  return 0;
}