%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128
#define pii pair <int, int>

const int N = 1002;
const int dx[8] = {-2, 2, -1, 1, -2, 2, -1, 1};
const int dy[8] = {-1, -1, -2, -2, 1, 1, 2, 2};

int wd[N][N], wp[N][N];
int bd[N][N], bp[N][N];
int n, m;
int wX, wY, bX, bY;

bool is_white;

void wsolve(int sx, int sy) {
  wd[sx][sy] = 0, wp[sx][sy] = -1;
  queue <pii> q;
  q.push(make_pair(sx, sy));
  while (!q.empty()) {
    pii u = q.front(); q.pop();
    int cx = u.first, cy = u.second;
    int cd = wd[cx][cy];
    for (int j = 0; j < 8; j++) {
      int x = cx + dx[j], y = cy + dy[j];
      if (x < 1 || x > n || y < 1 || y > m) continue;
      if (wd[x][y] <= cd + 1) continue; // vis[x][y]
      wd[x][y] = cd + 1;
      wp[x][y] = j;
      q.push(make_pair(x, y)); 
    }
  }
}

void bsolve(int sx, int sy) {
  bd[sx][sy] = 0, bp[sx][sy] = -1;
  queue <pii> q;
  q.push(make_pair(sx, sy));
  while (!q.empty()) {
    pii u = q.front(); q.pop();
    int cx = u.first, cy = u.second;
    int cd = bd[cx][cy];
    for (int j = 0; j < 8; j++) {
      int x = cx + dx[j], y = cy + dy[j];
      if (x < 1 || x > n || y < 1 || y > m) continue;
      if (bd[x][y] <= cd + 1) continue; // vis[x][y]
      bd[x][y] = cd + 1;
      bp[x][y] = j;
      q.push(make_pair(x, y));
    }
  }
}

void replay() {
  int newx, newy;
  cin >> newx >> newy;
  
  if (newx == -1) exit(0); // end
  
  if (is_white) bX = newx, bY = newy;
  else wX = newx, wY = newy;
}

bool play(int ifb) {
  int wturns = wd[wX][wY];
  int bturns = bd[bX][bY];
  int wblock = bd[wX][wY];
  int bblock = wd[bX][bY];
  
  if (ifb) { // black move
    if (bturns <= wturns) {
      if (bturns < wblock)
        return false;
      if (bturns % 2 == wblock % 2) return true;
      else return false;
    }
    else {
      if (wturns < bblock - 1)
        return true;
      if (wturns % 2 == bblock % 2) return true;
      else return false; 
    }
  }
  else { // white move
    if (wturns <= bturns) {
      if (wturns < bblock)
        return true;
      if (wturns % 2 == bblock % 2) return false;
      else return true;
    }
    else {
      if (bturns < wblock - 1)
        return false;
      if (bturns % 2 == wblock % 2) return false;
      else return true;
    }
  }
}

int main() {
  ios :: sync_with_stdio(false); cin.tie(0);

  cin >> n >> m;
  cin >> wX >> wY >> bX >> bY;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      wd[i][j] = 1e9;
      bd[i][j] = 1e9;
    }
  }
  
  wsolve(n / 2, m / 2);
  bsolve(n / 2 + 1, m / 2);
  
  if (play(0)) {
    is_white = true;
    cout << "WHITE" << "\n" << flush;
  }
  else {
    is_white = false;
    cout << "BLACK" << "\n" << flush;
    replay();
  }
  
  while (true) {
    int bl = -1, bturns = 1e9;
    for (int i = 0; i < 8; i++) {
      if (is_white) {
        wX += dx[i], wY += dy[i];
        if (wX >= 1 && wX <= n && wY >= 1 && wY <= m) {
          if (play(1) && wd[wX][wY] < bturns) {
            bturns = wd[wX][wY];
            bl = i;
          }
        }
        wX -= dx[i], wY -= dy[i];
      }
      else {
        bX += dx[i], bY += dy[i];
        if (bX >= 1 && bX <= n && bY >= 1 && bY <= m) {
          if (!play(0) && bd[bX][bY] < bturns) {
            bturns = bd[bX][bY];
            bl = i;
          }
        }
        bX -= dx[i], bY -= dy[i];
      }
    }
    
    if (is_white) {
      wX += dx[bl], wY += dy[bl];
      cout << wX << ' ' << wY << '\n' << flush;
    }
    else {
      bX += dx[bl], bY += dy[bl];
      cout << bX << ' ' << bY << '\n' << flush;
    }
    
    // end if
    if (is_white && wX == n / 2 && wY == m / 2) 
      break;
    if (!is_white && bX == n / 2 + 1 && bY == m / 2)
      break;
    if (wX == bX && wY == bY)
      break;
    
    replay();
  }
  //cout << flush;
  return 0;
}