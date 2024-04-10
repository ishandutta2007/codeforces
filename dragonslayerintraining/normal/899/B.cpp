#include <cstdio>

int month[12*5]={
  31,28,31,30,31,30,31,31,30,31,30,31,
  31,28,31,30,31,30,31,31,30,31,30,31,
  31,29,31,30,31,30,31,31,30,31,30,31,
  31,28,31,30,31,30,31,31,30,31,30,31,
  31,28,31,30,31,30,31,31,30,31,30,31
};

int days[24];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&days[i]);
  }
  for(int start=0;start<12*5-N;start++){
    int i;
    for(i=0;i<N;i++){
      if(days[i]!=month[start+i]){
	break;
      }
    }
    if(i==N){
      printf("YES\n");
      return 0;
    }
  }
  printf("NO\n");
  return 0;
}