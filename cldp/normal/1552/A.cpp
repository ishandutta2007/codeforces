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
    int n;
    string s;
    cin >> n >> s;
    string t = s;
    sort(t.begin(), t.end());
    int diff = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] != t[i]) ++diff;
    }
    cout << diff << "\n";
  }
  return 0;
}