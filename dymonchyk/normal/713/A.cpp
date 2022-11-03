#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

map<int, int> f;

int code(string s) {
  reverse(s.begin(), s.end());
  s += string(18, '0');
  
  int ret = 0;
  for (int i = 0; i < 18; ++i) {
    ret = (ret << 1) | ((s[i] - '0') & 1);
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  while (n--) {
    string c, s;
    cin >> c >> s;
    if (c == "+") {
      f[code(s)]++;
    } else if (c == "-") {
      f[code(s)]--;
    } else {
      cout << f[code(s)] << endl;
    }
  }
  return 0;
}