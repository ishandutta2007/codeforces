%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

const int ans[] = {
 0,1,1,1,2,1,2,1,5,2,2,1,5,1,2,1,14,1,5,1,5,2,2,1,
 15,2,2,5,4,1,4,1,51,1,2,1,14,1,2,2,14,1,6,1,4,2,2,
 1,52,2,5,1,5,1,15,2,13,2,2,1,13,1,2,4,267,1,4,1,5,
 1,4,1,50,1,2,3,4,1,6,1,52,15,2,1,15,1,2,1,12,1,10,
 1,4,2};

int n;

int main() {
  scanf("%d", &n);
  printf("%d\n", ans[n]);
  return 0;
}