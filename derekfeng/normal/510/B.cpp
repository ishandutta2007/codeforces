#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string.h>
using namespace std;
int n,m;
char s[53][53];
void dfs(int num,int i,int j,int x,int y,bool ww[53][53]){
  num++;
  if(x<0||x>=n||y<0||y>=m) return;
  if (num>=4&&i==x&&j==y){
    cout<<"Yes";
    exit(0);
  }
  if ((!ww[x][y])&&(s[x][y]==s[i][j])){
    ww[x][y]=true;
    dfs(num,i,j,x+1,y,ww);
    dfs(num,i,j,x-1,y,ww);
    dfs(num,i,j,x,y+1,ww);
    dfs(num,i,j,x,y-1,ww);
  }
}
int main(){
  cin>>n>>m;
  for (int i=0;i<n;i++)
    cin>>s[i];
  for (int i=0;i<n;i++)
    for (int j=0;j<m;j++){
      bool ww[53][53];
      int num=0;
      memset(ww,0,sizeof(ww));
      dfs(num,i,j,i,j,ww);
	}
  cout<<"No";
  return 0;
}