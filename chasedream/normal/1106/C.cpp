%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

const int N = 300005;
int a[N], n;

long long sqr(long long p) {
  return p * p;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  } 
  sort(a + 1, a + n + 1);
  
  long long ans = 0LL;
  for (int i = 1, j = n; i < j; i++, j--) {
    ans += sqr(a[i] + a[j]);
  }
  printf("%lld\n", ans); return 0;
}


//