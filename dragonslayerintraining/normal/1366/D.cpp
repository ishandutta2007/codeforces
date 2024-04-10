#include <cstdio>

int N;

int xs[500005];
int ys[500005];

void solve(int i,int A,int p){
  int B=1;
  while(A%p==0){
    A/=p;
    B*=p;
  }
  if(A!=1){
    xs[i]=A;
    ys[i]=B;
  }
}

int main(){
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    xs[i]=-1;
    ys[i]=-1;
    if(A%2==0){
      solve(i,A,2);
    }else if(A%3==0){
      solve(i,A,3);
    }else if(A%5==0){
      solve(i,A,5);
    }else for(int k=6;k*k<=A;k+=6){
      if(A%(k+1)==0){
	solve(i,A,k+1);
	break;
      }
      if(A%(k+5)==0){
	solve(i,A,k+5);
	break;
      }
    }
  }
  for(int i=0;i<N;i++){
    if(i) printf(" ");
    printf("%d",xs[i]);
  }
  printf("\n");
  for(int i=0;i<N;i++){
    if(i) printf(" ");
    printf("%d",ys[i]);
  }
  printf("\n");
}