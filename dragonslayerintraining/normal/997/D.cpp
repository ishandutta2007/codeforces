#include <cstdio>
#include <vector>
#include <stdint.h>

const int64_t MOD=998244353;


struct Graph{
  std::vector<int64_t> elist,next;
  std::vector<int64_t> head;
  void resize(int64_t N){
    head.resize(N);
  }
  void add_he(int64_t x){
    next.push_back(head[x]);
    head[x]=elist.size();
    elist.push_back(x);
  }
}tree[2];

int64_t self[2][40][4000];
int64_t selfe[2][40][8000];
int64_t avoide[2][40][8000];
int64_t flat[2][40];

int64_t pascal[80][80];

int main(){
  for(int64_t i=0;i<80;i++){
    pascal[i][0]=pascal[0][i]=1;
  }
  for(int64_t i=1;i<80;i++){
    for(int64_t j=1;j<80;j++){
      pascal[i][j]=(pascal[i][j-1]+pascal[i-1][j])%MOD;
    }
  }
  int64_t N[2],K;
  scanf("%I64d %I64d %I64d",&N[0],&N[1],&K);
  if(K%2==1){
    printf("0\n");
    return 0;
  }
  K/=2;
  for(int64_t t=0;t<2;t++){
    tree[t].resize(N[t]);
    for(int64_t i=0;i<N[t]-1;i++){
      int64_t U,V;
      scanf("%I64d %I64d",&U,&V);
      U--,V--;
      tree[t].add_he(U);
      tree[t].add_he(V);
    }
    for(int64_t e=0;e<tree[t].elist.size();e++){
      avoide[t][0][e]=1;
      selfe[t][0][e]=1;
    }
    for(int64_t i=0;i<N[t];i++){
      self[t][0][i]=1;
    }
    flat[t][0]=N[t];
    for(int64_t k=1;k<=K;k++){
      for(int64_t e=0;e<tree[t].elist.size();e++){
	int64_t i=tree[t].elist[e],j=tree[t].elist[e^1];
	if(k==1){
	  avoide[t][k][e]=1;
	}else{
	  avoide[t][k][e]=self[t][k-1][j];
	  for(int64_t l=1;l<k;l++){
	    avoide[t][k][e]=(avoide[t][k][e]+MOD-avoide[t][l][e]*selfe[t][k-l][e]%MOD)%MOD;
	  }
	}
	selfe[t][k][e]=0;
	for(int64_t l=1;l<=k;l++){
	  selfe[t][k][e]=(selfe[t][k][e]+avoide[t][l][e]*self[t][k-l][i]%MOD)%MOD;
	}
	self[t][k][i]=(self[t][k][i]+selfe[t][k][e])%MOD;
	
	//printf("SELFE %I64d %I64d %I64d=>%I64d =%I64d\n",t,k,i,j,selfe[t][k][e]);
	//printf("AVOIDE %I64d %I64d %I64d=>%I64d =%I64d\n",t,k,i,j,avoide[t][k][e]);
	
	flat[t][k]=(flat[t][k]+selfe[t][k][e])%MOD;
      }
      /*
      for(int64_t i=0;i<N[t];i++){
	printf("SELF %I64d %I64d %I64d=%I64d\n",t,k,i,self[t][k][i]);
      }
      printf("FLAT %I64d %I64d=%I64d\n",t,k,flat[t][k]);
      */
    }
  }
  int64_t ans=0;
  for(int64_t k=0;k<=K;k++){
    ans=(ans+flat[0][k]*flat[1][K-k]%MOD*pascal[2*k][2*(K-k)])%MOD;
  }
  printf("%I64d\n",ans);
  return 0;
}