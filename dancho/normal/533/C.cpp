#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int winP(int xp, int yp, int xv, int yv) {
  if (xp + yp <= max(xv, yv)) {
    return true;
  }

  int di = xv - yv;
  int db = xp - yp;
  int pp = di - db;
  if (pp < 0) {
    pp = -pp;
  }

  int pv;
  if (db > di) {
    pv = yv - yp;
  } else {
    pv = xv - xp;
  }
  if (pp <= pv) {
    return true;
  }
  return false;
}

int main() {
  int xp, yp, xv, yv;
  scanf("%d %d %d %d", &xp, &yp, &xv, &yv);

  if (winP(xp, yp, xv, yv)) {
    printf("Polycarp\n");
  } else {
    printf("Vasiliy\n");
  }
  return 0;
}