%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

const int N = 100005;
int a[N], n;

bool cmp(int x, int y) {
  return x > y;
}
void work() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a + 1, a + n + 1, cmp);
  int k = a[2] - 1;
  printf("%d\n", min(k, n - 2));
}

int main() {
  int T; scanf("%d", &T);
  while (T--) work();
  return 0;
}