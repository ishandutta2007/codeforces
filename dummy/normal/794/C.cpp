#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 6;
char a[N], b[N], s[N];

int main() {
  scanf("%s %s", a, b);
  int n = strlen(a);
  sort(a, a+n);
  sort(b, b+n);
  reverse(b, b+n);
  int l = 0, r = n-1, p = 0, q = 0, cnt = 0;
  while (a[p] < b[q] && cnt < n) {
    if ((cnt & 1) == 0)
      s[l++] = a[p++];
    else
      s[l++] = b[q++];
    cnt++;
  }
  if (cnt < n) {
    int sisa = n-cnt;
    if ((cnt & 1) == 0) {
      for (int i = cnt; i < n; i++) {
        if ((n-i) & 1)
          s[i] = a[p++];
        else
          s[i] = b[q++]; 
      }
    }
    else {
      for (int i = cnt; i < n; i++) {
        if (((n-i) & 1) == 0)
          s[i] = a[p++];
        else
          s[i] = b[q++]; 
      }
    }
  }
  s[n] = 0;
  printf("%s\n", s);
  return 0;
}