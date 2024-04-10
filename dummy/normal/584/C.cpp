#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
char s[N], r[N], ans[N];

int main() {
  int n, t;
  scanf("%d%d", &n, &t);
  scanf("%s%s", s, r);
  int cnt = 0; 
  for(int i = 0; i<n; i++) {
    cnt += (s[i] != r[i]);
    ans[i] = s[i];
  }
  ans[n] = '\0';
  if(cnt < t) {
    t -= cnt;
    for(int i = 0; i<n; i++) {
      if(ans[i] != r[i]) {
        if(ans[i] == 'z')
          ans[i] = 'a';
        else
          ans[i]++;
        if(ans[i] == r[i]) {          
          if(ans[i] == 'z')
            ans[i] = 'a';
          else
            ans[i]++;
        }
      }
      else {
        if(t) {
          if(ans[i] == 'z')
            ans[i] = 'a';
          else
            ans[i]++;
          t--;
        }
      }
    }
    if(t)
      puts("-1");
    else
      printf("%s\n", ans);
  }
  else { // t <= cnt
    if(2*t < cnt) {
      puts("-1");
      return 0;
    }
    int x = cnt-t, y = x;
    for(int i = 0; i<n; i++) if(s[i] != r[i]) {
      if(x) {
        ans[i] = s[i];
        x--;
      }
      else if(y) {
        ans[i] = r[i];
        y--;
      }
      else {
        if(ans[i] == 'z')
          ans[i] = 'a';
        else
          ans[i]++;
        if(ans[i] == r[i]) {          
          if(ans[i] == 'z')
            ans[i] = 'a';
          else
            ans[i]++;
        }
      }
    }
    if(x + y) {
      puts("-1");
      return 0;
    }
    printf("%s\n", ans);
  }
}