#include <cstdio>
#include <algorithm>

int as[200005];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  int prev=-1e9;
  for(int i=0;i<N;i++){
    if(!as[i]) prev=i;
    as[i]=i-prev;
  }
  prev=1e9;
  for(int i=N-1;i>=0;i--){
    if(!as[i]) prev=i;
    as[i]=std::min(as[i],prev-i);
  }
  for(int i=0;i<N;i++){
    if(i) printf(" ");
    printf("%d",as[i]);
  }
  printf("\n");
  return 0;
}