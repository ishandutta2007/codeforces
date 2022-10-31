%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128
 
const int N = 100005;
ll a[N], sum;
int n;
 
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    sum += a[i];
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] * 2 > sum) {
      puts("NO");
      exit(0);
    }
  }
  if (sum % 2 == 0) puts("YES"); else puts("NO");
  return 0;
}