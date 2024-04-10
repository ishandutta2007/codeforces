#include <cstdio>
#include <algorithm>

int N;

int sum=0;
int sign=1;
int min=1e9;

int main(){
  scanf("%d",&N);
  for(int i=0;i<2*N-1;i++){
    int A;
    scanf("%d",&A);
    if(A<0){
      A=-A;
      sign=-sign;
    }
    sum+=A;
    min=std::min(min,A);
  }
  if((N%2==1)||(sign==1)){
    printf("%d\n",sum);
  }else{
    printf("%d\n",sum-min*2);
  }
  return 0;
}