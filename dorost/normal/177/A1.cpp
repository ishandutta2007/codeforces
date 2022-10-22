#include<bits/stdc++.h>

using namespace std;

#define ll long long int

int main(){
  int n;
  cin >> n;
  int a[n][n],sum = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> a[i][j];
      sum+=a[i][j];
    }
  }
  if(n == 1 || n == 2 || n == 3 || n == 4){
    cout << sum;
  }
  if(n == 5){
    cout << sum - a[1][0] - a[0][1] - a[0][3] - a[3][0] - a[1][4] - a[4][1] - a[4][3] - a[3][4];
  }
}