%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128
 
const int N = 250005;
char s[N];
 
int main() {
  int T; scanf("%d\n", &T);
  
  while (T--) {
    scanf("%s", s);
    int cw = 0, cd = 0;
    int ma = 0, md = 0, mw = 0, ms = 0;
    int sa = 0, sd = 0, sw = 0, ss = 0;
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
      if (s[i] == 'W') cw++;
      if (s[i] == 'S') cw--;
      if (s[i] == 'D') cd++;
      if (s[i] == 'A') cd--;
      
      mw = max(mw, cw);
      ms = min(ms, cw);
      md = max(md, cd);
      ma = min(ma, cd);
      
      sw = max(sw, cw - ms);
      ss = max(ss, mw - cw);
      sd = max(sd, cd - ma);
      sa = max(sa, md - cd);
    }
    
    ll x[2], y[2];
    x[0] = max(sw, ss);
    x[1] = max((long long)(sw or ss), x[0] - !(sw == ss));
    y[0] = max(sd, sa);
    y[1] = max((long long)(sd or sa), y[0] - !(sd == sa));
    
    ll ans = min((x[0] + 1) * (y[1] + 1), (x[1] + 1) * (y[0] + 1));
    printf("%lld\n", ans);
  } 
  return 0;
}
 //