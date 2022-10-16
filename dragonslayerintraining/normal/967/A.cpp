#include <cstdio>
#include <algorithm>

bool bad[301*60];

int main(){
  int N,S;
  scanf("%d %d",&N,&S);
  for(int i=0;i<N;i++){
    int h,m;
    scanf("%d %d",&h,&m);
    int t=h*60+m;
    for(int i=std::max(0,t-S);i<=t+S;i++){
      bad[i]=true;
    }
  }
  for(int i=0;;i++){
    if(!bad[i]){
      printf("%d %d\n",i/60,i%60);
      return 0;
    }
  }
  return 0;
}