#include <iostream>

using namespace std;

int n,m;
int grid[55][55];

int g(int i, int j) {
  if(i < 0 || j < 0) return 0;
  return grid[i][j];
}

int s(int a, int b) {
  int ans = 0x7fffffff;
  for(int i = 0; i+a-1 < n; ++i) {
    for(int j = 0; j+b-1 < m; ++j) {
      ans = min(ans, g(i-1,j-1) + g(i+a-1,j+b-1) - g(i-1,j+b-1) - g(i+a-1,j-1));
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m;
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < m; ++j)
      cin >> grid[i][j];
  int a,b;
  cin >> a >> b;
  for(int i = 1; i < n; ++i)
    for(int j = 0; j < m; ++j)
      grid[i][j] += grid[i-1][j];
  for(int i = 0; i < n; ++i)
    for(int j = 1; j < m; ++j)
      grid[i][j] += grid[i][j-1];

  cout << min(s(a,b),s(b,a)) << "\n";

  return 0;
}