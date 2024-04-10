%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128
 
const int N = 100005;
struct Node {
  int num, id;
  bool operator < (const Node& b) const {
    return num < b.num;
  } 
} a[N];
int ans[N], b[N], n;
map <int, int> mp;
 
int main() {
  //srand(time(NULL));
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i].num);
    a[i].id = i;
    b[i] = a[i].num;
  }
  sort(b + 1, b + n + 1);
  int m = 0;
  for (int i = 1; i <= n; i++) {
    if (b[i] == b[i + 1]) {
      b[++m] = b[i]; b[++m] = b[i + 1];
      int j = i + 1;
      while (b[j + 1] == b[i]) j++;
      i = j;
    }
    else {
      b[++m] = b[i]; 
    }
  }
  /*
  for (int i = 1; i <= m; i++)
    printf("%d ", b[i]);
  putchar('\n');
  */
  int p = m / 2, ok = 0;
  int begin_time = clock();
  while (true) {
    if (clock() - begin_time >= 470) break;
    random_shuffle(b + 1, b + m + 1);
    int g1 = b[1];
    for (register int i = 2; i <= p; i++) {
      g1 = __gcd(g1, b[i]);
      if (g1 == 1) break;
    }
    if (g1 != 1) continue;
    int g2 = b[p + 1];
    for (register int i = p + 2; i <= m; i++) {
      g2 = __gcd(g2, b[i]);
      if (g2 == 1) break;
    }
    if (g2 != 1) continue;
    
    ok = 1; break;
  }
  if (!ok) {
    puts("NO"); exit(0);
  }
  puts("YES");
/*
  for (int i = 1; i <= m; i++)
    printf("%d ", b[i]);
  putchar('\n');
*/
  sort(b + 1, b + p + 1); sort(b + p + 1, b + m + 1);
  
/*
  for (int i = 1; i <= m; i++)
    printf("%d ", b[i]);
  putchar('\n');
*/
  for (int i = 1; i <= n; i++) {
    int fake = lower_bound(b + 1, b + p + 1, a[i].num) - b;
    if (fake <= p && b[fake] == a[i].num && !mp[a[i].num]) {
      mp[a[i].num] = 1;
      printf("1 "); continue;
    }
    printf("2 ");
  }
  return 0;
}