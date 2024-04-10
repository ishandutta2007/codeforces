#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
char s[N];

int main() {
  scanf("%d", &n);
  scanf("%s", s);
  char last = s[0];
  int ans = 1, cnt, a, b;
  cnt = a = b = 0;
  cnt = 1;
  for(int i = 1; i<n; i++) {
    if(s[i] != last) {
      ans++;
      last = s[i];
      if(cnt > a) {
        b = a;
        a = cnt;
      }
      else {
        if(cnt > b)
          b = cnt;
      }
      cnt = 1;
    }
    else {
      cnt++;
    }
  }
  if(cnt > a) {
    b = a;
    a = cnt;
  }
  else {
    if(cnt > b)
      b = cnt;
  }
  if((a > 1 && b >1) || (a >= 3))
    ans += 2;
  else if(a > 1)
    ans++;
  cout << ans << endl;
  return 0;
}