#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

string to(int x) {
  return string(1, char('0' + x / 10)) + string(1, char('0' + x % 10));
}

int get(int h1, int m1, int h2, int m2) {
  string s1 = to(h1) + to(m1);
  string s2 = to(h2) + to(m2);
  int cnt = 0;
  for (int i = 0; i < s1.size(); ++i)
    cnt += s1[i] != s2[i];
  return cnt;
}

int main() {
  int n, h, m;
  scanf("%d\n%d:%d\n", &n, &h, &m);

  int d = 1e+9, H, M;
  for (int i = (n == 12); i < (n == 12 ? 13 : 24); ++i)
    for (int j = 0; j < 60; ++j) {
      if (get(h, m, i, j) < d) {
        d = get(h, m, i, j);
        H = i; M = j;
      }
    }
  printf("%02d:%02d\n", H, M);

  return 0;
}