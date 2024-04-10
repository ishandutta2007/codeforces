%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128
 
const int N = 1005;
 
long long s[N][N], ans;
int n, m;
 
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    string str;
    cin >> str;
    for (int j = 1; j <= m; j++) {
      s[j][str[j - 1] - 'A']++;
    }
  }
  
  for (int i = 1; i <= m; i++) {
    long long x; scanf("%lld", &x);
    long long y = 0;
    for (int j = 0; j < 26; j++) {
      y = max(y, s[i][j]);
    }
    ans += x * y;
  }
  printf("%lld\n", ans);
  return 0;
}