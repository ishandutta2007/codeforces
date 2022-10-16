#include <cstdio>

int dollar[]={100,20,10,5,1};

int main(){
  int N;
  scanf("%d",&N);
  int ans=0;
  for(int d:dollar){
    ans+=N/d;
    N%=d;
  }
  printf("%d\n",ans);
  return 0;
}