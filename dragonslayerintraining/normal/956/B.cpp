#include <cstdio>
#include <algorithm>

int es[100005];

int main(){
  int N,U;
  scanf("%d %d",&N,&U);
  for(int i=0;i<N;i++){
    scanf("%d",&es[i]);
  }
  bool possible=false;
  double best=0;
  int i=N-1;
  for(int j=N-1;j>=0;j--){
    while(es[i]-es[j]>U){
      i--;
    }
    if(j+1<i){
      possible=true;
      best=std::max<double>(best,double(es[i]-es[j+1])/(es[i]-es[j]));
    }
  }
  if(possible){
    printf("%.10lf\n",best);
  }else{
    printf("-1\n");
  }
  return 0;
}