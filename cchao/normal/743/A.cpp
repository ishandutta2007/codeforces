#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define REPE(i, a, b) for (int i = (a); i <= int(b); ++i)
using LL = long long;
char s[100010];
int n, a, b;

int main() {
  scanf("%d%d%d%s", &n, &a, &b, s);
  --a, --b;
  if (s[a] == s[b]) puts("0");
  else puts("1");
  return 0;
}