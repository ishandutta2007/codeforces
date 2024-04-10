#include <cstdio>

int times[1024];
int copy[1024];

int main(){
  int N,K,X;
  scanf("%d %d %d",&N,&K,&X);
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    times[A]++;
  }
  for(int k=0;k<K;k++){
    for(int i=0;i<1024;i++){
      copy[i]=times[i];
      times[i]=0;
    }
    int prev=0;
    for(int i=0;i<1024;i++){
      if(prev%2==0){
	times[i^X]+=(copy[i]+1)/2;
	times[i]+=copy[i]/2;
      }else{
	times[i]+=(copy[i]+1)/2;
	times[i^X]+=copy[i]/2;
      }
      prev+=copy[i];
    }
  }
  int min=0,max=1e9;
  for(int i=0;i<1024;i++){
    if(times[i]){
      min=i;
      break;
    }
  }
  for(int i=0;i<1024;i++){
    if(times[i]){
      max=i;
    }
  }
  printf("%d %d\n",max,min);
  return 0;
}