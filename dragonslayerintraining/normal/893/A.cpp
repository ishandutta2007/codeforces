#include <cstdio>

int spec=3;

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    if(spec){
      spec^=A;
    }
  }
  if(spec){
    printf("YES\n");
  }else{
    printf("NO\n");
  }
  return 0;
}