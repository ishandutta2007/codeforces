#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> a(3); int d;
  scanf ("%d %d %d %d",&a[0],&a[1],&a[2],&d);
  sort (a.begin(),a.end());
  printf ("%d\n",max(d-(a[1]-a[0]),0)+max(d-(a[2]-a[1]),0));
  return 0;
}