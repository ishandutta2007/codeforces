#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int main() {
  set<char> f = {'a', 'e', 'i', 'o', 'u', 'y'};
  int n;
  cin >> n;
  int p[102] = {0};
  for (int i = 0; i < n; ++i)
    cin >> p[i];
  string s;
  getline(cin, s);
  for (int i = 0; i < n; ++i) {
    getline(cin, s);
    int cnt = 0;
    for (int j = 0; j < s.size(); ++j)
      if (f.count(s[j])) ++cnt;
    if (cnt != p[i]) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}