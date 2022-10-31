#include<iostream>
#include <stdio.h>
#include<string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdint>
#include <map>
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main(){


  int n,m;
  cin >> n >> m;
  
  char f[110][110];
  
  for(int i = 0; i< n; i++){
    for(int j = 0; j< m; j++){
      char c;
      cin >> c;
      if(c == '.') c = '0';
      f[i][j] = c;
    }
  }
  
  int x[8] = {-1,0,1,-1,1,-1,0,1};
  int y[8] = {-1,-1,-1,0,0,1,1,1};
  
  for(int i = 0; i< n; i++){
    for(int j = 0; j< m; j++){
      if(f[i][j] != '*'){
        int bomb = 0;
        for(int k = 0; k< 8; k++){
          if(f[i+x[k]][j+y[k]] == '*') bomb++;
        }
        if(bomb != f[i][j] - '0') {
          cout << "NO" << endl; return 0;
        }
      }
    }
  }
        cout << "YES" << endl;
return 0;
}