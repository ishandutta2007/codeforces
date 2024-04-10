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

string s, t;

bool Check(int a, int b) {
  int now = a;
  bool add = true;
  for (int i = 0; i < t.size(); ++i) {
    if (now < 0) return false;
    if (s[now] != t[i]) return false;
    if (now == b) add = false;
    if (add) ++now; else --now;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int times;
  cin >> times;
  while (times--) {
    cin >> s >> t;
    bool flag = false;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] != t[0]) continue;
      for (int j = i; j < s.size(); ++j) {
        if (Check(i, j)) {
          flag = true;
          break;
        }
      }
      if (flag) break;
    }
    if (flag) cout << "YES\n"; else cout << "NO\n";
  }
  return 0;
}