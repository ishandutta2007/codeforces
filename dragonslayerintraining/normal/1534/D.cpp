#include <cstdio>
#include <algorithm>
#include <cassert>
#include <vector>

int depth[2005];
int up[2005];
int par[2005];
int N;

void query(int x,int res[2005]){
  printf("? %d\n",x);
  fflush(stdout);
  for(int i=1;i<=N;i++){
    scanf("%d",&res[i]);
  }
}


int main(){
  scanf("%d",&N);
  query(1,depth);
  std::vector<int> ord;
  for(int i=1;i<=N;i++){
    if(depth[i]==0){
      par[i]=-1;
    }else if(depth[i]==1){
      par[i]=1;
    }else{
      ord.push_back(i);
    }
  }
  std::sort(ord.begin(),ord.end(),[](int a,int b){
      return depth[a]>depth[b];
    });
  for(int i:ord){
    if(par[i]) continue;
    query(i,up);
    for(int j=1;j<=N;j++){
      if(depth[j]==depth[i]-1&&up[j]==1){
	par[i]=j;
	break;
      }
    }
    assert(par[i]);
    if(!par[par[i]]){
      for(int j=1;j<=N;j++){
	if(depth[j]==depth[i]-2&&up[j]==2){
	  par[par[i]]=j;
	  break;
	}
      }
      assert(par[par[i]]);
    }
    //fprintf(stderr,"par[%d]=%d\n",i,par[i]);
    for(int j=1;j<=N;j++){
      if(depth[j]==depth[i]&&up[j]==2){
	par[j]=par[i];
	//fprintf(stderr,"par[%d]=%d\n",j,par[j]);
	//break;
      }
    }
  }
  printf("!\n");
  for(int i=2;i<=N;i++){
    printf("%d %d\n",i,par[i]);
  }
  fflush(stdout);
}