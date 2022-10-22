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
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

bool Check(string& s) {
  int cnt = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '(') ++cnt; else --cnt;
    if (cnt < 0) return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int times;
  cin >> times;
  while (times--) {
    int n;
    string s;
    cin >> n >> s;
    vector<int> x, y;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '0') y.push_back(i); else x.push_back(i);
    }
    if (x.size() % 2 == 1) {
      cout << "NO" << endl;
      continue;
    }
    string s1 = s, s2 = s;
    for (int i = 0; i < x.size() / 2; ++i) {
      s1[x[i]] = s2[x[i]] = '(';
    }
    for (int i = x.size() / 2; i < x.size(); ++i) {
      s1[x[i]] = s2[x[i]] = ')';
    }
    for (int i = 0; i < y.size(); ++i) {
      if (i % 2 == 0) {
        s1[y[i]] = '(';
        s2[y[i]] = ')';
      } else {
        s1[y[i]] = ')';
        s2[y[i]] = '(';
      }
    }
    if (!Check(s1) || !Check(s2)) {
      cout << "NO" << endl;
      continue;
    }
    cout << "YES" << endl;
    cout << s1 << endl << s2 << endl;
  }
  return 0;
}