#include <iostream>

using namespace std;

int R,C,k;
string grid[505];

bool bounds(int r, int c) {
  return r >= 0 && c >= 0 && r < R && c < C;
}

int dfs(int r, int c, int a) {
  if(!bounds(r,c) || grid[r][c] != '.' || a <= 0) return 0;
  grid[r][c] = 1;
  int b = a;
  --a;
  a -= dfs(r+1,c,a);
  a -= dfs(r-1,c,a);
  a -= dfs(r,c+1,a);
  a -= dfs(r,c-1,a);
  return b-a;
}

int main() {
  ios::sync_with_stdio(0);
  cin >> R >> C >> k;
  for(int i = 0; i < R; ++i)
    cin >> grid[i];
  int tot = 0;
  for(int r = 0; r < R; ++r)
    for(int c = 0; c < C; ++c)
      tot += grid[r][c] == '.';
  for(int r = 0; r < R; ++r) {
    for(int c = 0; c < C; ++c) {
      if(grid[r][c] == '.') {
        dfs(r, c, tot-k);
        goto skp;
      }
    }
  }
  skp:;
  for(int r = 0; r < R; ++r) {
    for(int c = 0; c < C; ++c) {
      char q = grid[r][c];
      if(q == 1) cout << '.';
      else if(q == '.') cout << 'X';
      else cout << q;
    }
    cout << "\n";
  }

  return 0;
}