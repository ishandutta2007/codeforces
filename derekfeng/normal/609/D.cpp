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
int N,M,K,bestday[2][200002];
long long S,c[2][200002],V;
int lo,hi,mid,best=20000000;
vector <pair<int,long long> > v;
struct gadget{
  long long cost;
  int ind;
  bool type;
  bool operator <(const gadget &o) const{
  	return cost*c[type][mid]<o.cost*c[o.type][mid];
  }
}g[200002];
bool check(){
  sort(g,g+M);
  V=0;
  int got=0;
  v.clear();
  for (int i=0;i<M;i++){
    V+=g[i].cost*c[g[i].type][mid];
    if (V>S) break;
    v.push_back({g[i].ind,bestday[g[i].type][mid]});
    got++;
 }
  return got >= K;
}
int main(){
  scanf("%d%d%d%lld",&N,&M,&K,&S);
  for(int d=0;d<2;d++)
    for(int i=0;i<N;i++){
      scanf("%lld",&c[d][i]);
      bestday[d][i]=i+1;
      if (i){
        if (c[d][i]>c[d][i-1]) bestday[d][i]=bestday[d][i-1];
        c[d][i]=min(c[d][i],c[d][i-1]);
	  }
    }
  for (int i=0;i<M;i++){
    int temp;
    scanf("%d%lld",&temp,&g[i].cost);
    g[i].type=temp==2;
    g[i].ind=i+1;
  }
  lo=0,hi=N-1;
  while (lo<=hi){
    mid=(lo+hi)/2;
    if (check()){
      best=min(best,mid);
      hi=mid-1;
	}else{
	  lo=mid+1;
	}
  }
  if (best==20000000){
    puts("-1");
	return 0;
  }
  printf("%d\n",best+1);
  mid=best;
  check();
  for (int i=0;i<v.size();i++){
    if (K){printf("%d %lld\n",v[i].first,v[i].second);K--;}
  }
  return 0;
}