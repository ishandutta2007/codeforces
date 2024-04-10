%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128
 
const int N = 505;
int a[N << 1];
int n;
 
bool check1() {
  for (int i = 1; i <= n; i++) {
    int ok = 1;
    for (int j = i; j <= i + n - 1; j++) {
      if (a[j] != j - i + 1) {
        ok = 0; break;
      }
    }
    if (ok) return 1;
  }
  return 0;
}
 
bool check2() {
  for (int i = n; i <= 2 * n; i++) {
    int ok = 1;
    for (int j = i; j >= i - n + 1; j--) {
      if (a[j] != i - j + 1) {
        ok = 0; break;
      }
    }
    if (ok) return 1;
  }
  return 0;
}
 
int main() {
  int T; scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      a[i + n] = a[i];
    }
    if (check1() || check2()) puts("YES"); else puts("NO");
  }
  return 0;
}