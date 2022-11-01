#define _USE_MATH_DEFINES
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <complex>
#include <cmath>
#include <numeric>
#include <bitset>
#include <functional>

using namespace std;

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " |";
  __f(comma + 1, args...);
}

typedef long long int64;
typedef pair<int, int> ii;
const int INF = 1 << 29;
const int MOD = 1e9 + 7;

char ret[300];

int main() {
  vector<int> a(2);
  int x;
  cin >> a[0] >> a[1] >> x;
  ++x;
  string ret;
  if (a[0] > a[1]) {
    for (int i = 0; i < x - 2; ++i) {
      ret += (char)('0' + i % 2);
      a[i % 2]--;
    }
    for (int i = x - 2; i < x; ++i) {
      ret += string(a[i % 2], (char)('0' + i % 2));
    }
  } else {
    for (int i = 0; i < x - 2; ++i) {
      ret += (char)('0' + 1 - i % 2);
      a[1 - i % 2]--;
    }
    for (int i = x - 2; i < x; ++i) {
      ret += string(a[1 - i % 2], (char)('0' + 1 - i % 2));
    }
  }
  cout << ret << endl;
  return 0;
}