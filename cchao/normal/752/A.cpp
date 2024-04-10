#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define REPE(i, a, b) for (int i = (a); i <= int(b); ++i)
using LL = long long;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  c--;
  int a1 = c / (b * 2) + 1;
  int tmp = c % (b * 2);
  int a2 = tmp / 2 + 1;
  char a3 = tmp % 2 == 0 ? 'L' : 'R';
  cout << a1 << ' ' << a2 << ' ' << a3 << endl;
  return 0;
}