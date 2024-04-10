#include <cstdio>

int main(){
  int B,K;
  scanf("%d %d",&B,&K);
  int res=0;
  for(int i=0;i<K;i++){
    int A;
    scanf("%d",&A);
    res=(res*B+A)%2;
  }
  printf("%s\n",res?"odd":"even");
  return 0;
}