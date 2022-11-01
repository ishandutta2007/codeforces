#include <bits/stdc++.h>

using namespace std;

int n, s;
int wait[1003];

int main() {
  scanf("%d%d", &n, &s);
  for(int i = 0; i<n; i++) {
    int f, t;
    scanf("%d%d", &f, &t);
    wait[f] = max(wait[f], t);
  }
  int ans = 0;
  for(int i = s; i> 0; i--) {
    ans = max(ans, wait[i]);
    ans++;
  }
  printf("%d\n", ans);
  return 0;
}