%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

long long n, k;

int main() {
  scanf("%lld%lld", &n, &k);
  long long sq = (long long)sqrt(9 + 8 * n + 8 * k);
  cout << n - (-3 + sq) / 2LL << '\n';
  return 0;
}