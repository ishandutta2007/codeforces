#include <stdio.h>
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <set>
#include <cmath>
#include <cstdlib>
#include <map>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <stdlib.h>
#include <assert.h>
#include <complex>
#include <cstring>

using namespace std;

typedef long long ll;

typedef complex<double> cd;

const long long INF = 1000000000;
const double PI = 3.141592653589793;

string s, t;

int sb[2][3][100100];

enum Tp {
  S = 0,
  T = 1
};

enum Letter {
  A = 0,
  B = 1,
  C = 2
};

int getCount(Tp string, Letter let, int l, int r) {
  return sb[string][let][r] - sb[string][let][l];
}

int getASuffix(Tp string, int l, int r) {
  int l1 = l - 1, r1 = r;
  while (r1 - l1 > 1) {
    int m = (l1 + r1) / 2;
    if (getCount(string, A, m, r) == r - m)
      r1 = m;
    else
      l1 = m;
  }
  return r - r1;
}

void printAns(int ls, int rs, int lt, int rt) {

  if (ls == rs) {
    if (lt == rt) {
      cout << 1;
    } else {
      cout << 0;
    }
    return;
  }




  int Ssuf = getASuffix(S, ls, rs);
  int Tsuf = getASuffix(T, lt, rt);
  if (Ssuf < Tsuf) {
    cout << 0;
    return;
  }

  if (Ssuf > 0 && Ssuf == Tsuf) {
    printAns(ls, rs - Ssuf, lt, rt - Tsuf);
    return;
  }


  int BCs = (rs - ls) - getCount(S, A, ls, rs), BCt = (rt - lt) - getCount(T, A, lt, rt);
  if (BCs % 2 != BCt % 2) {
    cout << 0;
    return;
  }
  if (BCs > BCt) {
    cout << 0;
    return;
  }
  if (BCs < BCt) {
    cout << 1;
    return;
  }
  if (Ssuf % 3 != Tsuf % 3) {
    cout << 0;
    return;
  }
  cout << 1;
}

void solve() {
  cin >> s >> t;
  int n = s.size();
  int m = t.size();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 3; ++j)
      sb[0][j][i + 1] = sb[0][j][i];
    ++sb[0][s[i] - 'A'][i + 1];
  }
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < 3; ++j)
      sb[1][j][i + 1] = sb[1][j][i];
    ++sb[1][t[i] - 'A'][i + 1];
  }

  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int ls, rs, lt, rt;
    cin >> ls >> rs >> lt >> rt;
    --ls;
    --lt;

    printAns(ls, rs, lt, rt);
  }
  
}

void init() {

}

int main() {
  iostream::sync_with_stdio(false);
  cin.tie(0);
  init();
  solve();
  return 0;
}