#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll mod = 1e9+7;

ll D[5010][5010];
int C[5010][5010];

string a;

bool comp(int x, int y, int d){
  if(y + d > a.size()) return false;
  if(C[x][y] != -1 and C[x][y] < d) return true;
  return false;
}

int main(){
  int n;
  cin >> n;
  cin >> a;
  
  for(int i = n - 1; i >= 0; --i){
    for(int j = n - 1; j > i; --j){
      if(a[i] < a[j]) C[i][j] = 0;
      else if(a[i] > a[j]) C[i][j] = -1;
      else{
	if(j == n - 1) C[i][j] = -1;
	else if(C[i + 1][j + 1] == -1) C[i][j] = -1;
	else C[i][j] = C[i + 1][j + 1] + 1;
      }
    }
  }
  
  for(int i = n - 1; i >= 0; --i){
    if(a[i] == '0') continue;
    for(int j = n - i; j >= 1; --j){
      if(i + j == n) D[i][j] = 1ll;
      else {
	if(comp(i, i + j, j)) D[i][j] = D[i + j][j];
	else D[i][j] = D[i + j][j + 1];
	D[i][j] = (D[i][j] + D[i][j + 1])%mod;
      }
    }
  }
  
  cout << D[0][1] << endl;
}