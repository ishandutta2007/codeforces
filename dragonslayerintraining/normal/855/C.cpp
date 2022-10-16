#include <cstdio>
#include <vector>
#include <stdint.h>

const int64_t MOD=1e9+7;

int64_t N,M,K,X;

std::vector<int64_t> conn[100000];

int64_t lt[100000][11];
int64_t ne[100000][11];
int64_t any[100000][11];
  

void combine(int64_t a[11],int64_t b[11],int64_t c[11]){
  for(int64_t i=0;i<=10;i++){
    for(int64_t j=0;j<=10-i;j++){
      c[i+j]=(c[i+j]+a[i]*b[j])%MOD;
    }
  }
}

void merge(int64_t a[11],int64_t b[11]){
  int64_t tmp[11];
  std::fill(tmp,tmp+11,0);
  combine(a,b,tmp);
  for(int64_t i=0;i<=10;i++){
    a[i]=tmp[i];
  }
}

void dfs(int64_t node,int64_t parent){
  for(int64_t child:conn[node]){
    if(child!=parent){
      dfs(child,node);
    }
  }
  int64_t cmp[3][11];//< = >
  for(int64_t k=0;k<3;k++){
    std::fill(cmp[k],cmp[k]+11,0);
  }
  cmp[0][0]=K-1;
  cmp[1][1]=1;
  cmp[2][0]=M-K;
  for(int64_t child:conn[node]){
    if(child!=parent){
      merge(cmp[0],any[child]);
      merge(cmp[1],lt[child]);
      merge(cmp[2],ne[child]);
    }
  }
  for(int64_t i=0;i<=10;i++){
    lt[node][i]=cmp[0][i];
    ne[node][i]=(cmp[0][i]+cmp[2][i])%MOD;
    any[node][i]=(cmp[0][i]+cmp[2][i]+cmp[1][i])%MOD;
  }
}

int main(){
  scanf("%I64d %I64d",&N,&M);
  for(int64_t i=0;i<N-1;i++){
    int64_t U,V;
    scanf("%I64d %I64d",&U,&V);
    U--,V--;
    conn[U].push_back(V);
    conn[V].push_back(U);
  }
  scanf("%I64d %I64d",&K,&X);
  dfs(0,0);
  int64_t sum=0;
  for(int64_t i=0;i<=X;i++){
    sum=(sum+any[0][i])%MOD;
  }
  printf("%I64d\n",sum);
  return 0;
}