#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>
#include <sstream>

using namespace std;

const int N = 2e+6;
int pr[N + 2], pal[N + 2];

bool isPal(int i) {
  ostringstream ss;
  ss << i;
  string s = ss.str();
  reverse(s.begin(), s.end());
  return s == ss.str();
}

int main() {
  int p, q;
  cin >> p >> q;
  // p = 42; q = 1; 

  pr[1] = true;
  for (int i = 2; i <= N; ++i) {
    if (!pr[i])
      for (int j = i + i; j <= N; j += i)
        pr[j] = 1;
  }
  for (int i = 1; i <= N; ++i) {
    pal[i] = isPal(i);
    // if (pal[i])
    //   cout << i << endl;
  }
  for (int i = 1; i <= N; ++i) {
    pr[i] = pr[i - 1] + (!pr[i]);
    pal[i] += pal[i - 1];
  }
  int l = 0, r = N;
  for (int i = 1; i <= N; ++i) {
    // int m = (l + r) >> 1;
    // if (1LL * q * pr[m] <= 1LL * p * pal[m]) l = m;
    // else r = m;
    if (1LL * q * pr[i] <= 1LL * p * pal[i])
      l = i;
  }
  // cout << pr[172] << " " << pal[172] << endl;
  cout << l << endl;
  return 0;
}