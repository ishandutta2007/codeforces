%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

long long n;

int main() {
  ios :: sync_with_stdio(false); cin.tie(0);
  cin >> n;
  long long ans = n * (n + 1) / 2;
  if (ans & 1) puts("1");
  else puts("0");
  return 0;
}