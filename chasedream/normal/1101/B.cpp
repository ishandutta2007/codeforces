%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

const int N = 500005;
char s[N];
int n, cnt;

int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  int x = 1, y = n;
  int x1, y1;
  for (; x <= n && s[x] != '['; x++) ;
  for (; y >= 1 && s[y] != ']'; y--) ;
  for (x1 = x + 1; x1 < n && s[x1] != ':'; x1++) ;
  for (y1 = y - 1; y1 > x1 && s[y1] != ':'; y1--) ;
  
  if (x1 >= y1 || x >= y) {
    puts("-1");
  } else {
    int tot = 0;
    for (int i = x1 + 1; i < y1; i++)
      if (s[i] == '|') tot++;
    printf("%d\n", tot + 4); 
  }
  return 0;
}
// wlzhouzhuan, 233