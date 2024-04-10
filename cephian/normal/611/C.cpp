#include <iostream>
#include <sstream>
#include <set>
#include <algorithm>
#include <cstdio>
#include <map>
#include <cmath>

using namespace std;

int hor[505][505];
int ver[505][505];


int R, C, q;
string grid[505];

bool f(int i, int j) {
  return grid[i][j] == '.';
}

int gh(int i, int j) {
  if(i < 0 || j < 0) return 0;
  return hor[i][j];
}

int gv(int i, int j) {
  if(i < 0 || j < 0) return 0;
  return ver[i][j];
}

int get(int r1,int c1,int r2,int c2) {
  return gh(r2, c2)-gh(r2, c1) - gh(r1-1, c2) + gh(r1-1,c1)  +   gv(r2, c2) + gv(r1,c1-1)-gv(r2,c1-1)-gv(r1,c2);
}

int main() {
  ios::sync_with_stdio(0);
  cin >> R >> C;
  for(int i = 0; i < R; ++i)
    cin >> grid[i];

  for(int r = 0; r < R; ++r) {
    hor[r][0] = 0;
    for(int c = 1; c < C; ++c) {
      hor[r][c] = hor[r][c-1];
      if(f(r, c) && f(r, c-1))
        ++hor[r][c];
    }
  }
  for(int r = 1; r < R; ++r)
    for(int c = 0; c < C; ++c)
      hor[r][c] += hor[r-1][c];

  for(int c = 0; c < C; ++c) {
    ver[0][c] = 0;
    for(int r = 1; r < R; ++r) {
      ver[r][c] = ver[r-1][c];
      if(f(r, c) && f(r-1, c))
        ++ver[r][c];
    }
  }
  for(int c = 1; c < C; ++c)
    for(int r = 0; r < R; ++r)
      ver[r][c] += ver[r][c-1];
  cin >> q;
  for(int i = 0; i < q; ++i) {
    int r1,c1,r2,c2;
    cin >>r1>>c1>>r2>>c2;
    --r1;
    --c1;
    --r2;
    --c2;
    cout << get(r1,c1,r2,c2) << "\n";
  }

  return 0;
}