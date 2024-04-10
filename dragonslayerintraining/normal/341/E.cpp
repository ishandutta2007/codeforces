#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cassert>
#include <algorithm>

int N;
int as[1000];

std::vector<std::pair<int,int> > moves;

void move_left(int i,int j){
  assert(as[i]<=as[j]);
  as[j]-=as[i];
  as[i]*=2;
  moves.emplace_back(i,j);
}

int main(){
  scanf("%d",&N);
  int x[3]={-1,-1,-1};
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
    if(as[i]>0){
      if(x[0]==-1){
	x[0]=i;
      }else if(x[1]==-1){
	x[1]=i;
      }else{
	x[2]=i;
	std::sort(x,x+3,[](int j,int k){return as[j]>as[k];});
	while(as[x[2]]>0){
	  int q=as[x[1]]/as[x[2]];
	  for(int k=0;(1<<k)<=q;k++){
	    if(q&(1<<k)){
	      move_left(x[2],x[1]);
	    }else{
	      move_left(x[2],x[0]);
	    }
	  }
	  std::sort(x,x+3,[](int j,int k){return as[j]>as[k];});
	}
      }
    }
  }
  if(x[1]==-1){
    printf("-1\n");
  }else{
    printf("%d\n",(int)moves.size());
    for(auto m:moves){
      printf("%d %d\n",m.first+1,m.second+1);
    }
  }
}