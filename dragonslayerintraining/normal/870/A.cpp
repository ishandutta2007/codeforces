#include <cstdio>
#include <algorithm>

int cnt[10];
int min[2]={10,10};

int main(){
  int N[2];
  scanf("%d %d",&N[0],&N[1]);
  for(int k=0;k<2;k++){
    for(int i=0;i<N[k];i++){
      int X;
      scanf("%d",&X);
      cnt[X]++;
      min[k]=std::min(min[k],X);
    }
  }
  for(int i=0;i<10;i++){
    if(cnt[i]==2){
      printf("%d\n",i);
      return 0;
    }
  }
  if(min[0]>min[1]){
    std::swap(min[0],min[1]);
  }
  printf("%d%d\n",min[0],min[1]);
  return 0;
}