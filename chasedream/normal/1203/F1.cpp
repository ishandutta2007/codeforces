%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128
 
const int N = 205;
struct ele {
  int a, b;
} a[N], b[N];
int p, q;
 
bool cmp1(ele x, ele y) {
  if (x.a != y.a) return x.a < y.a;
  else return x.b < y.b;
}
 
bool cmp2(ele x, ele y) {
  int sum1 = x.a + x.b, sum2 = y.a + y.b;
  if (sum1 != sum2) return sum1 > sum2;
  else return x.a > y.a;
}
 
int n, r;
 
int main() {
  scanf("%d%d", &n, &r);
  for (int i = 1; i <= n; i++) {
    int x, y; scanf("%d%d", &x, &y);
    if (y > 0) {
      a[++p] = ele{x, y};
    }
    else {
      b[++q] = ele{x, y};
    }
  }
  sort(a + 1, a + p + 1, cmp1); sort(b + 1, b + q + 1, cmp2);
  
  for (int i = 1; i <= p; i++) {
    if (r < a[i].a) {
      puts("NO"); exit(0);
    }
    r += a[i].b;
  }
  
  for (int i = 1; i <= q; i++) {
    if (r < b[i].a) {
      puts("NO"); exit(0);
    }
    r += b[i].b;
    if (r < 0) {
      puts("NO"); exit(0);
    }
  } 
  
  if (r < 0) {
    puts("NO"); exit(0);
  }
  puts("YES");
  return 0;
}