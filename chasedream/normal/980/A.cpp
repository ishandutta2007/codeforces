%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

char s[10005];
int cnt1, cnt2;

int main() {
  scanf("%s", s);
  int len = strlen(s);
  for (int i = 0; i < len; i++) {
    if (s[i] == '-') cnt1++;
    else cnt2++;
  }
  if (cnt1 == 0 || cnt2 == 0) puts("YES");
  else if (cnt1 % cnt2 == 0) puts("YES");
  else puts("NO");
  return 0;
}

// wlzhouzhan, 233