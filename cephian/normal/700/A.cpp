#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <utility>

using namespace std;
typedef long long ll;

int n,k;
double l,v1,v2;

int main() {
  cin >> n >> l >> v1 >> v2 >> k;
  int r = max((n+k-1)/k,1);
  double t = l/(((v2-v1)/(v2+v1)+1)*v1*(r-1)+v2);
  double ans = t + (l-t*v2)/v1;
  printf("%.12lf\n",min(ans,l/v1));
  return 0;
}