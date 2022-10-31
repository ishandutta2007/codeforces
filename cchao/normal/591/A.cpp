#include <bits/stdc++.h>
using namespace std;

int main() {
  double a, b, c;
  cin >> a >> b >> c;
  a *= b / (b + c);
  printf("%.12f\n", a);
  return 0;
}