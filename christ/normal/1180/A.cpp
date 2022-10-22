#include <bits/stdc++.h>
using namespace std;
int ans[101];
int main() {
  ans[1] = 1;
  for (int x = 2; x <= 100; x++) {
    ans[x] = ans[x-1] + 4*(x-1);
  }
  int n;
  scanf ("%d",&n);
  printf ("%d\n",ans[n]);
  return 0;
}