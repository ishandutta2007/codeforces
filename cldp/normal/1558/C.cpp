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

int Find(const vector<int>& x, int a) {
  for (int i = 0; i < x.size(); ++i) {
    if (x[i] == a) return i;
  }
  return -1;
}

void Rotate(vector<int>& x, int L) {
  int i = 0, j = L - 1;
  while (i < j) {
    swap(x[i], x[j]);
    ++i;
    --j;
  }
}

void Print(vector<int>& x) {
  for (int i : x) cout << i + 1 << " ";
  cout << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int times;
  cin >> times;
  while (times--) {
    int n;
    cin >> n;
    vector<int> x(n);
    bool hasans = true;
    for (int i = 0; i < n; ++i) {
      cin >> x[i];
      --x[i];
      hasans &= ((x[i] - i) % 2 == 0);
    }
    if (!hasans) {
      cout << -1 << "\n";
      continue;
    }
    vector<int> ans;
    int R = n;
    for (int round = 0; round < (n - 1) / 2; ++round) {
      int t1 = Find(x, R - 2);
      int t2 = Find(x, R - 1);
      if (t1 == R - 2 && t2 == R - 1) {
        R -= 2;
        continue;
      }
      if (t2 != 0) {
        Rotate(x, t2 + 1);
        ans.push_back(t2 + 1);
        t2 = 0;
        t1 = Find(x, R - 2);
      }
      Rotate(x, t1);
      ans.push_back(t1);
      t2 = t1 - 1;
      Rotate(x, t1 + 2);
      ans.push_back(t1 + 2);
      Rotate(x, 3);
      ans.push_back(3);
      Rotate(x, R);
      ans.push_back(R);
      R -= 2;
    }
    cout << ans.size() << "\n";
    for (int i : ans) cout << i << " ";
    cout << "\n";
  }
  
  return 0;
}