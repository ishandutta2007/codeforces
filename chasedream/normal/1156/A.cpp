#include <bits/stdc++.h>
using namespace std;

const int N = 700005;
int a[N];
int n, ans;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 2; i <= n; i++) {
    if (a[i]==3&&a[i-1]==2 || a[i]==2&&a[i-1]==3) {
      puts("Infinite");
      return 0;
    }
    else {
      ans += a[i - 1] + a[i];
      if (i > 2 && a[i]==2&&a[i-1]==1&&a[i-2]==3){
        ans--;
      }
    }
  }
  puts("Finite");
  printf("%d\n", ans);
  return 0;
}