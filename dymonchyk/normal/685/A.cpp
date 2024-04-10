#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int getLen(int n) {
  int ret = (n == 0 ? 1 : 0);
  while (n > 0) {
    ++ret;
    n /= 7;
  }
  return ret;
}

int n, m;
set<pair<int, int>> f;

bool used[12];
vector<int> v;

int l1, l2;

int num(const vector<int> &vec, int l, int r) {
  int ret = 0;
  for (int i = l; i <= r; ++i) {
    ret = ret * 7 + vec[i];
  }
  return ret;
}

void go() {
  if (v.size() == l1 + l2) {
    // int zero = 0;
    // for (int x : v)
    //   zero += (x == 0);
    for (int i = l1; i <= l1; ++i) {
      int v1 = num(v, 0, i - 1), v2 = num(v, i, v.size() - 1);
      // int hasZ = (i < l1) + ((v.size() - i) < l2) + zero;
      if (v1 < n && v2 < m) {
        f.insert({v1, v2});
        // cout << v1 << " " << v2 << endl;
      }
    }
  }

  for (int i = 0; i < 7; ++i) {
    if (!used[i]) {
      used[i] = true;
      v.push_back(i);
      go();
      v.pop_back();
      used[i] = false;
    }
  }
}

int main() {
  cin >> n >> m;
  l1 = getLen(n - 1); l2 = getLen(m - 1);
  go();

  cout << f.size() << endl;
  return 0;
}