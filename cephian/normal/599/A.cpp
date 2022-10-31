#include <iostream>
#include <sstream>
#include <set>
#include <algorithm>
#include <cstdio>
#include <map>
#include <cmath>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  int a,b,c;
  cin >> a >> b >> c;
  int d = a+b+c;
  d = min(d, 2*(a+c));
  d = min(d, 2*(a+b));
  d = min(d, 2*(b+c));
  cout << d << "\n";

  return 0;
}