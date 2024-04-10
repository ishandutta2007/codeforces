%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128
 
const int N = 100005;
int a[N], n, x, y;
 
bool check(int k) {
  for (int i = max(1, k - x); i < k; i++)
    if (a[i] <= a[k]) return 0;
  for (int i = k + 1; i <= min(n, k + y); i++)
    if (a[i] <= a[k]) return 0;
  return 1;
}
 
int main() {
  scanf("%d%d%d", &n, &x, &y);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  } 
  for (int i = 1; i <= n; i++) {
    if (check(i)) {
      printf("%d\n", i);
      exit(0);
    }
  }
  return 0;
}