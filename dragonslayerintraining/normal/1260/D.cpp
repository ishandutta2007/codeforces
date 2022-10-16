#include <cstdio>
#include <algorithm>

const int INF=1e9+7;

int M,N,K,T;
int as[200005];

int ls[200005];
int rs[200005];
int ds[200005];

int trap[200005];

//min time if must avoid traps of skill >= $skill
int cost(int skill){
  std::fill(trap,trap+N+1,0);
  for(int i=0;i<K;i++){
    if(ds[i]>skill){
      trap[ls[i]-1]++;
      trap[rs[i]]--;
    }
  }
  int res=0;
  for(int i=0;i<=N;i++){
    trap[i+1]+=trap[i];
    if(trap[i]){
      res+=3;
    }else{
      res+=1;
    }
    //printf("%d",trap[i]);
  }
  //printf("\n");
  //printf("take >=%d: %d\n",skill,res);
  return res;
}

int main(){
  scanf("%d %d %d %d",&M,&N,&K,&T);
  for(int i=0;i<M;i++){
    scanf("%d",&as[i]);
  }
  for(int i=0;i<K;i++){
    scanf("%d %d %d",&ls[i],&rs[i],&ds[i]);
  }
  
  std::sort(as,as+M);
  int low=0,high=M+1;
  while(high-low>1){
    int mid=(low+high)/2;
    //Take top mid
    //printf("mid=%d\n",mid);
    if(cost(as[M-mid])<=T){
      low=mid;
    }else{
      high=mid;
    }
  }
  printf("%d\n",low);
}