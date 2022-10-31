%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

const int N = 200005;
int a[N], n;
int id = 0;

bool check() {
  for (int i = 1; i < id; i++)
    if (a[i] > a[i + 1]) return 0;
  for (int i = id + 1; i <= n; i++)
    if (a[i - 1] < a[i]) return 0;
  return 1;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (a[i] > a[id]) id = i; // get max
  }
  
  if (check()) puts("YES"); else puts("NO");
  return 0;
}
// wlzhouzhuan, 233