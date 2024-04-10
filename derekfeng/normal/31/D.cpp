//join This is an alpaca and have fun
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
#include <sstream>
#include <stack>
#include <time.h>
#include <vector>
#include <complex>
#include <map>
#include <set>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
#include<list>
#include <utility>
#include <memory>
#include <cstring>
#include <fstream>
#include <numeric>
#include <assert.h>
using namespace std;
int n,m,k;
int x1[100],y1[100],x2[100],y2[100],was[100][100];
vector <int> res;
int check(int ai,int aj,int bi,int bj){
  if (bi<0 || bj<0 || bi>=n || bj>=m || was[bi][bj]) return 0;
  if (ai > bi) swap(ai,bi);
  if (aj > bj) swap(aj,bj);
  if (ai!=bi){
    ai++;
    bj++;
  }
  else{
    aj++;
    bi++;
  }
  for (int i=0;i<k;i++){
    int ci=max(ai,x1[i]);
    int cj=max(aj,y1[i]);
    int di=min(bi,x2[i]);
    int dj=min(bj,y2[i]);
    if (ci<di && cj<=dj || ci<=di && cj<dj) return 0;
  }
  return 1;
}
int go(int i,int j){
  was[i][j]=1;
  int t=1;
  if (check(i,j,i+1,j)) t+=go(i+1,j);
  if (check(i,j,i-1,j)) t+=go(i-1,j);
  if (check(i,j,i,j+1)) t+=go(i,j+1);
  if (check(i,j,i,j-1)) t+=go(i,j-1);
  return t;
}
int main(){
  scanf("%d%d%d",&n,&m,&k);
  for (int i=0;i<k;i++) scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
  memset(was,0,sizeof(was));
  for (int i=0;i<n;i++)
    for (int j=0;j<m;j++)
      if (!was[i][j]) res.push_back(go(i,j));
  sort(res.begin(),res.end());
  for (int i=0;i<res.size();i++)
    cout<<res[i]<<" ";
  return 0;
}