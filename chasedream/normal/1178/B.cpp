#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string s; int n;
long long a, b, c;

int main() {
  cin >> s; n = s.size();
  for (int i = 0; i < n; i++) {
    if (s[i] == 'o') {
      b += a;
    } else if (i > 0 && s[i - 1] == 'v') {
      a ++;
      c += b;
    }
  }
  printf("%lld\n", c);
  return 0;
}