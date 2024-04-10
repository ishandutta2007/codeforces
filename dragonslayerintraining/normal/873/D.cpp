#include <cstdio>
#include <vector>

int K;

std::vector<int> vs;

void gen(int L,int R,int x){
  if(R-L==1){
    vs.push_back(x);
    return;
  }
  int M=(L+R)/2;
  if(K>0){
    K-=2;
    gen(L,M,x+R-M);
    gen(M,R,x);
  }else{ 
    gen(L,M,x);
    gen(M,R,x+M-L);
  }
}

int main(){
  int N;
  scanf("%d %d",&N,&K);
  if(K%2==0){
    printf("-1\n");
    return 0;
  }
  K--;
  gen(0,N,0);
  if(K>0){
    printf("-1\n");
    return 0;
  }
  for(int i=0;i<N;i++){
    if(i>0){
      printf(" ");
    }
    printf("%d",vs[i]+1);
  }
  printf("\n");
  return 0;
}