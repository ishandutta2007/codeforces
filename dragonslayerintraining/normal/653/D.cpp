#include <cstdio>
#include <iostream>
#include <iomanip>
#include <algorithm>

const int64_t INF=1e9+7;

int N,M,X;
int64_t orig[50][50];
int64_t cap[50][50];

bool vis[50];

int64_t augment(int64_t node,int64_t limit,int64_t scale){
  if(node==N-1) return limit;
  vis[node]=true;
  for(int64_t v=0;v<N;v++){
    if(!vis[v]&&cap[node][v]>=scale){
      int64_t tmp=augment(v,std::min(limit,cap[node][v]),scale);
      if(tmp){
	cap[node][v]-=tmp;
	cap[v][node]+=tmp;
	return tmp;
      }
    }
  }
  return 0;
}
	    

bool check(long double W){
  for(int64_t i=0;i<N;i++){
    for(int64_t j=0;j<N;j++){
      cap[i][j]=int64_t(orig[i][j]/W);
    }
  }
  int64_t flow=0;
  int64_t scale=INF;
  while(true){
    std::fill(vis,vis+N,false);
    int64_t f=augment(0,INF,scale);
    if(!f){
      scale>>=1;
      if(!scale){
	break;
      }
    }
    flow+=f;
  }
  //printf("flow(%.20Lf)=%d\n",W,flow);
  return flow>=X;
}

int main(){
  scanf("%d %d %d",&N,&M,&X);
  for(int64_t i=0;i<M;i++){
    int A,B,C;
    scanf("%d %d %d",&A,&B,&C);
    A--,B--;
    orig[A][B]=C;
  }
  long double low=0,high=1e9;
  while(true){
    long double mid=(low+high)/2;
    if(low==mid||high==mid) break;
    if(check(mid)){
      low=mid;
    }else{
      high=mid;
    }
  }
  std::cout<<std::fixed<<std::setprecision(10)<<low*X<<std::endl;
  //printf("%.10lf\n",double(low*X));
  return 0;
}