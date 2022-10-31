#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
char a[N], b[N];
int T, la, lb;

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%s%s", a, b);
    la = strlen(a);
    lb = strlen(b);
    int i = 0, flag = 0;
    for (int j = 0; j < lb; j++) {
      if (a[i] == b[j]) {
        if (a[i + 1] != a[i])
          while (j + 1 < lb && a[i] == b[j + 1]) j++;
        i++;
      }
      else flag = 1;
    }
    //printf("%d %d\n", i, flag);
    
    if (i == la && !flag) {
      puts("YES");
    }
    else {
      puts("NO");
    }
  }
  return 0;
}