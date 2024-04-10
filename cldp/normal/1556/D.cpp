#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

using LL = long long;

LL Qand(int a, int b) {
  cout << "and " << a << " " << b << endl;
  LL c;
  cin >> c;
  return c;
}

LL Qor(int a, int b) {
  cout << "or " << a << " " << b << endl;
  LL c;
  cin >> c;
  return c;
}

int main() {
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  LL ab = Qand(1, 2) + Qor(1, 2);
  LL ac = Qand(1, 3) + Qor(1, 3);
  LL bc = Qand(2, 3) + Qor(2, 3);
  vector<LL> x(n);
  x[0] = (ab + ac - bc) / 2;
  x[1] = (ab + bc - ac) / 2;
  x[2] = (ac + bc - ab) / 2;
  for (int i = 3; i < n; ++i) {
    LL sum = Qand(1, i + 1) + Qor(1, i + 1);
    x[i] = sum - x[0];
  }
  sort(x.begin(), x.end());
  cout << "finish " << x[k - 1] << endl;  
  return 0;
}