#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  int n,x,y;
  scanf ("%d %d %d",&n,&x,&y);
  vector<int> a(n);
  for (auto &ar : a) scanf ("%d",&ar);
  for (int i = 0; i < n; i++) {
      for (int j = max(i-x,0); j < i; j++) if (a[j] < a[i]) goto fail;
      for (int j = min(i+y,n-1); j > i; j--) if (a[j] < a[i]) goto fail;
      return !printf ("%d\n",i+1);
      fail:;
  }
  return 0;
}