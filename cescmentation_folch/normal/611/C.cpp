#include<bits/stdc++.h>

using namespace std;

int lin[500][500];
int col[500][500];
int ver[500][500];

int main(){
  int f, c;
  cin >> f >> c;
  
  for(int i = 0; i < f; ++i){
    int k = 0;
    for(int j = 0; j < c; ++j){
      char a;
      cin >> a;
      if(a == '.') ver[i][j] = 1;
      else ver[i][j] = 0;
      
      if(ver[i][j] and j > 0 and ver[i][j - 1]) ++k;
      lin[i][j] = k;
      if(i > 0) lin[i][j] += lin[i - 1][j];
    }
  }
  
  for(int j = 0; j < c; ++j){
    int k = 0;
    for(int i = 0; i < f; ++i){
      if(ver[i][j] and i > 0 and ver[i - 1][j]) ++k;
      col[i][j] = k;
      if(j > 0) col[i][j] += col[i][j - 1];
    }
  }
  
  int q;
  cin >> q;
  
  for(int tt = 0; tt < q; ++tt){
    int r1,c1,r2,c2;
    cin >> r1 >> c1 >> r2 >> c2;
    --r1;
    --c1;
    --r2;
    --c2;
    
    int rr = lin[r2][c2] + col[r2][c2];
    rr -= lin[r2][c1] + col[r1][c2];
    if(r1) rr += lin[r1 - 1][c1] - lin[r1 - 1][c2];
    if(c1) rr += col[r1][c1 - 1] - col[r2][c1 - 1];
    
    cout << rr << endl;
  }
}