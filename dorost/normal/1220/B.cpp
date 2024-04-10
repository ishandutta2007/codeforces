//***in the name of GOD***

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define str string

int main(){
  int n;
  long long c;
  cin >> n;
  int a[n][n];
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> a[i][j];
    }
  }
  c = sqrt(((long long)a[0][1] * a[0][2]) / (a[1][2]));
  cout << c << ' ';
  for(int i = 1; i < n; i++){
      cout << a[0][i] / c << ' ';
  }
}