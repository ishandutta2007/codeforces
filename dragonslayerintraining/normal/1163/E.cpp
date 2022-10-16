#include <cstdio>
#include <algorithm>

int ss[200005];

int basis[32];
int orig[32];

void add(int S){
  int T=S;
  for(int k=30;k>=0;k--){
    if(T&(1<<k)){
      T^=basis[k];
    }
    if(T&(1<<k)){
      basis[k]=T;
      orig[k]=S;
      break;
    }
  }
}

bool good(int x){
  for(int k=0;k<x;k++){
    if(orig[k]==0||orig[k]>=(2<<x)){
      return false;
    }
  }
  return true;
}

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&ss[i]);
  }
  std::sort(ss,ss+N);
  for(int i=0;i<N;i++){
    add(ss[i]);
  }
  /*
  for(int k=0;k<30;k++){
    printf("basis[%d]=%d\n",k,basis[k]);
  }
  */
  int x=30;
  while(!good(x)){
    x--;
  }
  printf("%d\n",x);
  for(int i=0;i<(1<<x);i++){
    int choose=i^(i>>1);
    int val=0;
    for(int k=0;k<30;k++){
      if(choose&(1<<k)){
	val^=orig[k];
      }
    }
    printf("%d ",val);
  }
  printf("\n");
}