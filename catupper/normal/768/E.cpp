#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
typedef long long Int;
/*
Int n, s;

map<Int, Int> cond[61];
vector<Int> conds[61];
void make_conds(int x){
  sort(conds[x].begin(), conds[x].end());
  conds[x].erase(unique(conds[x].begin(), conds[x].end()), conds[x].end());
  for(int i = 0;i < conds[x].size();i++){
    Int p = conds[x][i];
    for(int j = 1;j <= x;j++){
      if((1LL << j) & p)continue;
      Int np = p | (1LL << j);
      conds[x - j].push_back(np);
    }
  }
  cout << x << " " << conds[x].size() << endl;
}
int main(){
  for(int i = 0;i <= 60;i++)conds[i].push_back(0);
  for(int i = 60;i >= 1;i--)make_conds(i);
  for(int i = 0;i < conds[0].size();i++){
    Int c = conds[0][i];
    cond[0][c] = 0;
  }
  for(int i = 1;i <= 60;i++){
    for(int j = 0;j < conds[i].size();j++){
      Int p = conds[i][j];
      Int ban = 0;
      for(int k = 1;k <= i;k++){
	if((1LL << k) & p)continue;
	Int np = p | (1LL << k);
	ban |= (1LL << cond[i - k][np]);
      }
      for(int k = 0;k <= 60;k++){
	if((1LL << k) & ban)continue;
	cond[i][p] = k;
	break;
      }
    }
  }
  for(int i = 1;i <= 60;i++){
    cout << cond[i][0] << ", ";
  }
  return 0;
}
*/

int grandy[] = {0,1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10};

int main(){
  int n, s;
  int res = 0;
  cin >> n;
  for(int i = 0;i < n;i++){
    cin >> s;
    res ^= grandy[s];
  }
  if(res)cout << "NO" << endl;
  else cout << "YES" << endl;
  return 0;
}