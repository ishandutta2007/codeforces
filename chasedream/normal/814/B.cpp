#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
int a[N], b[N], s[N], cnt[N];
int n, pos, pos2;

bool setting(int id, int num) {
  for (int i = 1; i <= n; i++) {
    s[i] = a[i];
    if (i == id) s[i] = num;
  }
  
  int diff = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] != b[i]) diff++;
  }
  return diff == 1;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (cnt[a[i]]) pos = i;
    else cnt[a[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    if (cnt[i] == 0) pos2 = i;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &b[i]);
  }
  
  if (setting(cnt[a[pos]], pos2)) {
    for (int i = 1; i <= n; i++) printf("%d ", s[i]);
    putchar('\n');
  } 
  else if (setting(pos, pos2)) {
    for (int i = 1; i <= n; i++) printf("%d ", s[i]);
    putchar('\n');
  }
  return 0;
}