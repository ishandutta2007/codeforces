%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128
 
const int N = 50005;
int f[N];
int n;
int pos = -1;
 
void work() {
  scanf("%d", &n); pos = -1;
  for (int i = 50000; i >= 1; i--) {
    f[i] = 0;
    long long x = (long long)i * (i + 1LL) / 2;
    while (n >= x) {
      f[i]++; n -= x;
    }
    if (f[i] > 0 && pos == -1) {
      pos = i;
    }
  }
  string ans = "";
  for (int i = pos; i >= 0; i--) {
    while (f[i]) {
      ans += "1";
      f[i]--;
    }
    ans += "3";
  }
  cout << ans + "7" << '\n';
}
 
int main() {
  int T; scanf("%d", &T);
  while (T--) work();
  return 0;
}