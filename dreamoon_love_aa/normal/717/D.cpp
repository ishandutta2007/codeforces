#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

int n, x;

struct mat {
  double arr[128][128];
  void zero() {
    for (int i = 0; i < 128; i++)
    for (int j = 0; j < 128; j++)
    arr[i][j] = 0;
  }
  void identity() {
    zero();
    for (int i = 0; i < 128; i++) {
      arr[i][i] = 1;
    }
  }
  void init() {
    zero();
    for (int i = 0; i <= x; i++) {
      double p;
      cin >> p;
      for (int j = 0; j < 128; j++) {
        int tar = i ^ j;
        arr[j][tar] += p;
      }
    }
  }
  mat mul(mat &rhs) {
    mat ret;
    ret.zero();
    for (int i = 0; i < 128; i++) {
    for (int j = 0; j < 128; j++) {
    for (int k = 0; k < 128; k++) {
      ret.arr[i][j] += arr[i][k] * rhs.arr[k][j];
    }
    }
    }
    return ret;
  }
};

int main() {
	// your code goes here
  cin >> n >> x;
  mat m;
  m.init();
  mat t;
  t.identity();
  while (n > 0) {
    if ((n & 1) == 1) {
      t = t.mul(m);
    }
    m = m.mul(m);
    n >>= 1;
  }
  printf("%.15f\n", 1 - t.arr[0][0]);
	return 0;
}