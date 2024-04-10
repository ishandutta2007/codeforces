#include <cstdio>
#include <algorithm>

int ss[100001];

int main(){
  int N,A,B;
  scanf("%d %d %d",&N,&A,&B);
  for(int i=0;i<N;i++){
    scanf("%d",&ss[i]);
  }
  std::sort(ss+1,ss+N);
  for(int i=1;i<N;i++){
    ss[i]+=ss[i-1];
  }
  for(int i=N-1;;i--){
    if(ss[i]<=ss[0]*A/B){
      printf("%d\n",N-1-i);
      return 0;
    }
  }
  return 0;
}