%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128
 
const int N = 200005;
char a[N], b[N];
int n, m;
 
int main() {
  int T; scanf("%d\n", &T);
  while (T--) {
    scanf("%s%s", a, b);
    n = strlen(a);
    m = strlen(b);
    
    int idd;
    for (int i = m - 1; i >= 0; i--) {
      if (b[i] == '1') {
        idd = m - 1 - i;
        break;
      }
    }
    
    //printf("idd %d\n", idd);
    int id;
    for (int i = n - idd - 1; i >= 0; i--) {
      if (a[i] == '1') {
        id = n - 1 - i - idd;
        break;
      }
    }
    //printf("id %d\n", id);
    
    printf("%d\n", id);
  }
  return 0;
}
//