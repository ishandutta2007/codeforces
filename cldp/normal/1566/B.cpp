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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int times;
  cin >> times;
  while (times--) {
    string s;
    cin >> s;
    int one = 0, zero = 0;
    int n = s.size();
    for (int i = 0; i < n; ) {
      int j = i;
      while (j < n && s[j] == s[i]) ++j;
      if (s[i] == '0') ++zero; else ++one;
      i = j;
    }
    if (zero == 0) {
      cout << 0 << "\n";
      continue;
    }
    if (one == 0) {
      cout << 1 << "\n";
      continue;
    }
    cout << min(2, zero) << "\n";
  }
  
  return 0;
}