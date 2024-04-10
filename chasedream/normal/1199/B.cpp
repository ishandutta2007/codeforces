%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128
 
double H, L;
 
int main() {
  scanf("%lf%lf", &H, &L);
  printf("%.13lf\n", (L * L - H * H) / (2 * H));
  return 0;
}