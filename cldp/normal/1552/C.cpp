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

struct Node {
  int a, b;
};

bool Cross(Node a, Node b) {
  if (a.a > a.b) swap(a.a, a.b);
  if (b.a > b.b) swap(b.a, b.b);
  if (a.a > b.a) swap(a, b);
  return b.a < a.b && a.b < b.b;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int times;
  cin >> times;
  while (times--) {
    int n, k;
    cin >> n >> k;
    vector<Node> x(k);
    for (int i = 0; i < k; ++i) {
      cin >> x[i].a >> x[i].b;
      --x[i].a;
      --x[i].b;
    }
    vector<bool> z(n + n);
    for (int i = 0; i < k; ++i) {
      z[x[i].a] = true;
      z[x[i].b] = true;
    }
    vector<int> p;
    for (int i = 0; i < n + n; ++i) {
      if (z[i]) continue;
      p.push_back(i);
    }
    for (int i = 0; i < n - k; ++i) {
      x.push_back({p[i], p[i + n - k]});
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (Cross(x[i], x[j])) ++ans;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}