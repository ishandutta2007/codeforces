#include<bits/stdc++.h>
using namespace std;
char grid[505][505];
int main () {
    int n,m;
    scanf ("%d %d",&n,&m);
    for (int x = 0; x < n; x++) scanf ("%s",grid[x]);
    for (int x = 1; x < n-1; x++) {
      for (int y = 1; y < m-1; y++) {
        if (grid[x][y] == '*' && grid[x+1][y] == '*' && grid[x-1][y] == '*' && grid[x][y+1] == '*' && grid[x][y-1] == '*') {
          grid[x][y] = '.';
          for (int xx = x+1; xx < n && grid[xx][y] == '*'; xx++) grid[xx][y] = '.';
          for (int xx = x-1; xx >= 0 && grid[xx][y] == '*'; xx--) grid[xx][y] = '.';
          for (int yy = y+1; yy < m && grid[x][yy] == '*'; yy++) grid[x][yy] = '.';
          for (int yy = y-1; yy >= 0 && grid[x][yy] == '*'; yy--) grid[x][yy] = '.';
          goto success;
        }
      }
    }
    return !printf ("NO\n");
    success:
    for (int x = 0; x < n; x++) for (int y = 0; y < m; y++) if (grid[x][y] == '*') return !printf("NO\n");
    return !printf ("YES\n");
}