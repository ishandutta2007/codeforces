%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

const int N = 205;
int a[N], b[N];
int n, m;

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d", &b[i]);
  }
  if (m >= 2) {
    puts("Yes"); exit(0);
  }
  a[n + 1] = INT_MAX;
  for (int i = 1; i <= n; i++) {
    if (!a[i]) a[i] = b[1];
    if (!a[i + 1]) a[i + 1] = b[1];
    if (a[i] >= a[i + 1]) {
      puts("Yes"); exit(0);
    } 
  }
  puts("No"); return 0;
}