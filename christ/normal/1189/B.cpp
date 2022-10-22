#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf ("%d",&n);
  vector<int> arr(n), circle(n);
  for (auto &a :  arr) scanf ("%d",&a);
  sort(arr.begin(),arr.end());
  int sind = 0, eind = n-1;
  for (int i = 0; i < n; i++) {
    if (i & 1) circle[eind--] = arr[i];
    else circle[sind++] = arr[i];
  }
  for (int i = 1; i < n-1; i++) if (circle[i-1] + circle[i+1] <= circle[i]) return !printf ("NO\n");
  if (circle[n-1] + circle[1] <= circle[0]) return !printf ("NO\n");
  if (circle[0] + circle[n-2] <= circle[n-1]) return !printf ("NO\n");
  printf ("YES\n");
  for (int i = 0; i < n; i++) printf("%d%c",circle[i],i==n-1?'\n':' ');
  return 0;
}