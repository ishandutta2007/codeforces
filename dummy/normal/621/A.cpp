#include <bits/stdc++.h>

using namespace std;

const long long inf = 1e12;

int main() {
  int n;
  long long sum = 0, mi;
  mi = inf;
  scanf("%d", &n);
  for(int i = 0; i<n; i++) {
    int x;
    scanf("%d", &x);
    if(x & 1)
      mi = min(mi, (long long)x);
    sum += x;
  }
  if(sum & 1)
    sum -= mi;
  cout << sum << endl;
  return 0;
}