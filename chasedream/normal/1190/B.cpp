%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

const int N = 100005;
int a[N], n;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a + 1, a + n + 1);

  // 0  
  int cnt0 = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == 0) cnt0++;
  }
  if (cnt0 >= 2) {
    puts("cslnb"); exit(0);
  }

  //  
  int cnt = 0;
  for (int i = 1; i < n; i++) {
    if (a[i] == a[i + 1])
      cnt++;
  }
  if (cnt >= 2) { // the same
    puts("cslnb"); exit(0);
  }
  else if (cnt == 1) {
    for (int i = 2; i < n; i++) {
      if (a[i] == a[i + 1]) {
        if (a[i - 1] + 1 == a[i]) {
          puts("cslnb"); exit(0);
        }
        break;
      }
    }
  }
  
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += a[i] - (i - 1);
    ans &= 1;
  }
  if (ans == 1) puts("sjfnb");
  else puts("cslnb");
  return 0;
}

//