%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128
 
const int N = 100005;
int a[N], n;
int ans;
 
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a + 1, a + n + 1);
  int tail = 1;
  for (int i = 1; i <= n; i++) {
    while (tail < n && a[tail] <= a[i]) tail++;
    if (a[tail] > a[i]) {
      ans++; tail++;
    }
  }
  printf("%d\n", ans);
  return 0;
}