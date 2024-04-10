%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

const int N = 1000005;
string a, b;
int cnt[250][250], cnt2[250][2], n;

int main() {
  scanf("%d\n", &n);
  cin >> a >> b;
  a = ' ' + a, b = ' ' + b;
  //cerr << a << b << '\n';
  
  int wrong = 0;
  for (int i = 1; i <= n; i++)
    if (a[i] != b[i]) {
      wrong++;
      cnt2[a[i]][0] = i;
      cnt2[b[i]][1] = i;
    }

  for (int i = 1; i <= n; i++) {
    if (a[i] != b[i]) {
      cnt[a[i]][b[i]] = i;
      if (cnt[b[i]][a[i]]) {
        printf("%d\n", wrong - 2);
        printf("%d %d\n", i, cnt[b[i]][a[i]]);
        exit(0);
      }
    }
  }
  
  for (int i = 'a'; i <= 'z'; i++)
    if (cnt2[i][0] && cnt2[i][1]) {
      printf("%d\n", wrong - 1);
      printf("%d %d\n", cnt2[i][0], cnt2[i][1]);
      exit(0);
    }
  
  printf("%d\n", wrong);
  puts("-1 -1");
  return 0;
}