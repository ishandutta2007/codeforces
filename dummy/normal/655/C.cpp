#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n, k;
char s[N];
int id[N];

int main() {
  scanf("%d%d", &n, &k);
  scanf("%s", s);
  int ans = n;
  int cnt = 0;
  for(int i = 0; i<n; i++) if(s[i] == '0')
    id[cnt++] = i;
  n = cnt;
  int r = k;
  for(int i = 0; i<n; i++) {
    r = max(r, max(i, k));
    r = min(r, n-1);
    while(r > max(i, k) && id[r]-id[i] > id[i]-id[r-k]) r--;
    ans = min(ans, max(id[r]-id[i], id[i]-id[r-k]));
    while(r+1 < n && id[r]-id[i] <= id[i]-id[r-k]) {
      r++;
      ans = min(ans, max(id[r]-id[i], id[i]-id[r-k]));
    }
  }
  cout << ans << endl;
  return 0;
}