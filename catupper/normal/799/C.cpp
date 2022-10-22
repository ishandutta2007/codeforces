#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
#define INF (1<<29)
int n, c, d;
int b, p;
int res;
char C;
int fountain[2][108000];
int bb[108000];
int pp[108000];
char cc[108000];
vector<int> halfc, halfd;

int main(){
  cin >> n >> c >> d;
  for(int i = 0;i < 108000;i++){
    fountain[0][i] = fountain[1][i] = -INF;
  }

  for(int i = 0;i < n;i++){
    cin >> b >> p >> C;
    if(C == 'C'){
      fountain[0][p] = max(fountain[0][p], b);
    }
    if(C == 'D'){
      fountain[1][p] = max(fountain[1][p], b);
    }
    bb[i] = b;
    pp[i] = p;
    cc[i] = C;
  }
  for(int i = 1;i < 108000;i++){
    fountain[0][i] = max(fountain[0][i], fountain[0][i-1]);
    fountain[1][i] = max(fountain[1][i], fountain[1][i-1]);
  }
  for(int i = 0;i < n;i++){
    if(cc[i] == 'C' &&  c - pp[i] < 0)continue;
    if(cc[i] == 'D' &&  d - pp[i] < 0)continue;
    if(cc[i] == 'C'){
      int rem = min(c - pp[i], pp[i]-1);	  
      res = max(res, bb[i] + fountain[0][rem]);
    }
    if(cc[i] == 'D'){
      int rem = min(d - pp[i], pp[i]-1);
      res = max(res, bb[i] + fountain[1][rem]);
    }
  }
  res = max(res, fountain[0][c] + fountain[1][d]);
  for(int i = 0;i < n;i++){
    if(cc[i] == 'C' && c == pp[i] * 2)halfc.push_back(bb[i]);
    if(cc[i] == 'D' && d == pp[i] * 2)halfd.push_back(bb[i]);
  }
  sort(halfc.rbegin(), halfc.rend());
  sort(halfd.rbegin(), halfd.rend());
  if(halfc.size() >= 2)res = max(res, halfc[0] + halfc[1]);
  if(halfd.size() >= 2)res = max(res, halfd[0] + halfd[1]);
  cout << res << endl;
  return 0;
}