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

const int MAXN = 200010;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int times;
  cin >> times;
  while (times--) {
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> in(n);
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
      --v[i];
      ++in[v[i]];
    }
    vector<bool> z(n);
    queue<int> Q;
    for (int i = 0; i < n; ++i) {
      if (in[i] == 0) Q.push(i);
    }
    vector<int> ans(n, -1);
    vector<bool> rest(n, false);
    while (!Q.empty()) {
      int s = Q.front();
      Q.pop();
      if (z[v[s]]) {
        rest[s] = true;
      } else {
        z[v[s]] = true;
        ans[s] = v[s];
      }
      --in[v[s]];
      if (in[v[s]] == 0) {
        Q.push(v[s]);
      }
    }
    for (int i = 0; i < n; ++i) {
      if (!rest[i] && ans[i] == -1) {
        if (!z[v[i]]) {
          z[v[i]] = true;
          ans[i] = v[i];
        } else {
          rest[i] = true;
        }
      }
    }
    vector<int> rt;
    vector<int> zt;
    for (int i = 0; i < n; ++i) {
      if (rest[i] && !z[i]) {
        rt.push_back(i);
        zt.push_back(i);
      }
    }
    for (int i = 0; i < n; ++i) {
      if (rest[i] && z[i]) rt.push_back(i);
      if (!rest[i] && !z[i]) zt.push_back(i);
    }
    int mm = rt.size();
    for (int i = 0; i < mm; ++i) {
      ans[rt[i]] = zt[(i + 1) % mm];
    }
    cout << n - mm << "\n";
    for (int i : ans) cout << i + 1 << " ";
    cout << endl;
  }
  
  return 0;
}