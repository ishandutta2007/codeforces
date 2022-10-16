#include <cstdio>
#include <cstdlib>

int N;

int query(int i){
  printf("? %d\n",i%N+1);
  fflush(stdout);
  int x;
  scanf("%d",&x);
  return x;
}

void answer(int x){
  printf("! %d\n",(x<0)?-1:(x%N+1));
  exit(0);
}

int query_pair(int x){
  int diff=query(x)-query(x+N/2);
  if(diff==0){
    answer(x);
  }
  return diff;
}

int main(){
  scanf("%d",&N);
  if(N%4==2){
    answer(-1);
  }
  for(int i=0;i<N;i++){
    int low,high;
    //query_pair(low)<0
    //query_pair(high)>0
    if(query_pair(0)<0){
      low=0,high=N/2;
    }else{
      low=N/2,high=N;
    }
    while(true){
      int mid=(low+high)/2;
      if(query_pair(mid)<0){
	low=mid;
      }else{
	high=mid;
      }
    }
  }
  return 0;
}