#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e9;
vector<int> used;
vector<vector<int> > data;
bool ask(int a, int b, int c, int d){
  if (a > c || b > d){
    swap(a, c);
    swap(b, d);
  }
  cout << "? " << a+1 << " " << b+1 << " " << c+1 << " " << d+1 << endl;
  int res;
  cin >> res;
  return res;
}
signed main() {
  #ifdef LOCAL
    freopen("H_input.txt", "r", stdin);
    //freopen("C_output.txt", "w", stdout);
  #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    int matrix[n][n];
    for (int i=0; i < n; i++) for (int j=0; j < n; j++) matrix[i][j] = 2;
    matrix[0][0] = 1, matrix[n-1][n-1] = 0;
    for (int i=0; i < n; i++) for (int j=0; j < n; j++){
      if (matrix[i][j] != 2) continue;
      if ((i+j)%2) continue;
      int x = i, y = j-2;
      if (y < 0){
        x = i-1, y = j-1;
      }
      if (y < 0){
        x = i-2, y = j;
      }
      bool res = ask(x, y, i, j);
      if (res) matrix[i][j] = matrix[x][y];
      else matrix[i][j] = 1-matrix[x][y];
    }
    int change = -1;
    for (int i=0; i < n-2; i++){
      if (matrix[i][i] == 1 && matrix[i+1][i+1] == 0 && matrix[i+2][i+2] == 0){
        change = i;
        break;
      }
    }
    if (change != -1){
      bool a = ask(change, change, change+1, change+2);
      bool b = ask(change, change+1, change+2, change+2);
      if (a) matrix[change+1][change+2] = matrix[change][change];
      else if (b) matrix[change][change+1] = matrix[change+2][change+2];
      else{
        matrix[change][change+1] = 1;
      }
    }
    else{
      for (int i=0; i < n-2; i++){
        if (matrix[i][i] == 1 && matrix[i+1][i+1] == 1 && matrix[i+2][i+2] == 0){
          change = i;
          break;
        }
      }
      bool a = ask(change, change, change+1, change+2);
      bool b = ask(change, change+1, change+2, change+2);
      if (a) matrix[change+1][change+2] = matrix[change][change];
      else if (b) matrix[change][change+1] = matrix[change+2][change+2];
      else{
        matrix[change+1][change+2] = 0;
      }
    }
    while (true){
      bool ex = true;
      for (int i=0; i < n; i++) for (int j=0; j < n; j++){
        if (matrix[i][j] == 2) ex = false;
      }
      if (ex) break;
      for (int i=0; i < n; i++) for (int j=0; j < n; j++){
        if (matrix[i][j] != 2) continue;
        if ((i+j)%2==0) continue;
        int rx=-1, ry=-1;
        for (int dx=-2; dx <= 2; dx++) for (int dy=-2; dy <= 2; dy++){
          if (abs(dx) + abs(dy) != 2) continue;
          if ((dx*dy)<0) continue;
          int x = i+dx, y = j+dy;
          if (x < 0 || x >= n || y < 0 || y >= n) continue;
          if (matrix[x][y] == 2) continue;
          rx = x, ry = y;
          break;
        }
        if (rx==-1) continue;
        bool res = ask(rx, ry, i, j);
        if (res) matrix[i][j] = matrix[rx][ry];
        else matrix[i][j] = 1-matrix[rx][ry];
      }
    }
    cout << "!" << endl;
    for (int i=0; i < n; i++){
      for (int j=0; j < n; j++) cout << matrix[i][j];
      cout << endl;
    }
}