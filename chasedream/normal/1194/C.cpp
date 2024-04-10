%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

string a, b, c;
int n, m, k;
int cnt[250];

void work() {
  memset(cnt, 0, sizeof(cnt));

  cin >> a >> b >> c;
  n = a.size(); m = b.size(); k = c.size();
  int j = 0;
  for (int i = 0; i < m; i++) {
    if (b[i] == a[j]) {
      j++;
      //printf("match %d %d\n", j, i);
    }
    else cnt[b[i]]++;
  }
  if (j != n) {
    puts("NO"); return ;
  }
  for (int i = 0; i < k; i++)
    cnt[c[i]]--;
  for (int i = 'a'; i <= 'z'; i++)
    if (cnt[i] > 0) {
      //printf("cnt[%c]=%d\n", i, cnt[i]);
      puts("NO"); return ;
    }
  puts("YES"); return ;
}

int main() {
  int T; scanf("%d", &T);
  while (T--) work();
  return 0;
}