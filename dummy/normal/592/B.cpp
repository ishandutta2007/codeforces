#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  long long ans = 3LL*(n - 3LL) + 1LL*(n-3LL)*(n-4LL) + 1;
  cout << ans << endl;
  
  
  return 0;
}