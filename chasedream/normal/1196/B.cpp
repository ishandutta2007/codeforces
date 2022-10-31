#include <bits/stdc++.h>
using namespace std;
 
const int N = 1000005;
int a[N], b[N];
int n, k;
 
void work(){
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    a[i] %= 2;
  }
  int sum = 0, r = 0;
  for (int i = 1; i <= n; i++) {
    sum += a[i];
    if (sum & 1) b[++r] = i, sum = 0;
  }
  if (r < k) {
    puts("NO"); return ;
  }
  if ((r - k) & 1) {
    puts("NO"); return ;
  }
  puts("YES");
  for (int i = 1; i < k; i++)
    printf("%d ", b[i]);
  printf("%d\n", n);
}
 
int main(){
  int t ; scanf("%d", &t);
  while (t--) {
    work();
  }
  return 0;
}