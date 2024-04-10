%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

int a, b, c, d, e;

int main() {
  scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
  printf("%d\n", min(a, min(b, min(c / 2, min(d / 7, e / 4))))); 
  return 0;
}