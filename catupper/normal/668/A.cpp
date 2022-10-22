#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int n, m, qs;
int inp[10800][3];
int ans[108][108];
int q[10800];

int main(){
  cin >> n >> m >> qs;
  for(int i = 0;i < qs;i++){
    cin >> q[i];
    cin >> inp[i][0];
    if(q[i] == 3){
      cin >> inp[i][1] >> inp[i][2];
    }
  }

  for(int i = qs-1;i >= 0;i--){
    if(q[i] == 3){
      ans[inp[i][0]][inp[i][1]] = inp[i][2];
    }
    if(q[i] == 2){
      int tmp = ans[n][inp[i][0]];
      for(int j = n;j >= 1;j--){
	ans[j][inp[i][0]] = ans[j-1][inp[i][0]];
      }
      ans[1][inp[i][0]] = tmp;
    }
    if(q[i] == 1){
      int tmp = ans[inp[i][0]][m];
      for(int j = m;j >= 1;j--){
	ans[inp[i][0]][j] = ans[inp[i][0]][j-1];
      }
      ans[inp[i][0]][1] = tmp;
    }
  }
  for(int i = 1;i <= n;i++){
    for(int j = 1;j <= m;j++){
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
  
}