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

int Gcd(int a, int b) {
  while (b != 0) {
    int t = a % b;
    a = b;
    b = t;
  }
  return a;
}

const int MAXN = 6010;

int x[MAXN], y[MAXN];
LL odd[MAXN], even[MAXN];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int t = Gcd(abs(x[j] - x[i]), abs(y[j] - y[i])) / 2;
      if (t & 1) {
        ++odd[i];
        ++odd[j];
      } else {
        ++even[i];
        ++even[j];
      }
    }
  }
  LL anso = 0, anse = 0;
  for (int i = 0; i < n; ++i) {
    if (even[i] > 1) anse += even[i] * (even[i] - 1) / 2;
    if (odd[i] > 0 && even[i] > 0) anso += odd[i] * even[i];
  }
  cout << anse / 3 + anso / 2 << endl;  
  return 0;
}