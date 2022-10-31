%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

const int N = 300005;
int a[N], b[N];
int n, m;

bool check(int x, int y) {
  for (int i = 1; i <= m; i++) {
    if (a[i] != x && b[i] != x &&
        a[i] != y && b[i] != y) return 0;
  }  
  return 1;
}

int main() {
  scanf("%d%d", &n, &m);
  int p = 0;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &a[i], &b[i]);
    if (a[i] != a[1] && a[i] != b[1] &&
        b[i] != a[1] && b[i] != b[1]) p = i;
  }
  if (p == 0) {
    puts("YES"); exit(0);
  }
  if (check(a[1], a[p]) || check(a[1], b[p]) ||
      check(b[1], a[p]) || check(b[1], b[p])) puts("YES");
  else puts("NO");  
  return 0;
}