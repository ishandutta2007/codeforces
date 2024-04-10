%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

const int N = 100005;
long long p[N];
long long n, m, k;
long long lst, cur, block, ans;

int main() {
  scanf("%lld%lld%lld", &n, &m, &k);
  for (int i = 1; i <= m; i++)
    scanf("%lld", &p[i]);
  
  cur = 1;
  while (cur <= m) {
    lst = cur - 1;
    block = (p[cur] - lst + k - 1) / k;
    for (; (p[cur] - lst + k - 1) / k == block; cur++) ;
    ans++;
  }
  printf("%d\n", ans);
  return 0;
}