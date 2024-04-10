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
    cin >> n;
    vector<LL> x(n);
    for (int i = 0; i < n; ++i) cin >> x[i];
    sort(x.begin(), x.end());
    LL ans = 0;
    for (int i = 0; i < n - 1; ++i) {
      LL d = x[i + 1] - x[i];
      LL a = i + 1;
      LL b = n - a;
      ans -= d * (a * b - 1);
    }
    cout << ans << endl;
  }
  
  return 0;
}