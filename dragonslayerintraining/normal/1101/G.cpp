#include <cstdio>

int basis[30];

int main(){
  int N;
  scanf("%d",&N);
  int sum=0;
  int ans=0;
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    sum^=A;
    for(int k=30-1;k>=0;k--){
      if(A==0) break;
      if((A>>k)&1){
	if(basis[k]==0){
	  basis[k]=A;
	  ans++;
	  break;
	}else{
	  A^=basis[k];
	}
      }
    }
  }
  printf("%d\n",(sum==0)?-1:ans);
  return 0;
}