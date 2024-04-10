#include <bits/stdc++.h>
using namespace std;

int main() {
  long long a, b, c;
  cin >> a >> b >> c;
  if (c == 0) return puts(a == b ? "YES" : "NO"), 0;
  b -= a;
  puts(b % c == 0 && b / c >= 0 ? "YES" : "NO");
  return 0;
}