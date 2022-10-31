%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

const char *s = "01001010111001010";
int n;

int main() {
  scanf("%d", &n);
  printf("%c\n", s[n]);
  return 0;
}