#include <cstdio>
#include <algorithm>

int as[10];

int main(){
  int V;
  scanf("%d",&V);
  int min=1e9;
  for(int i=1;i<10;i++){
    scanf("%d",&as[i]);
    min=std::min(min,as[i]);
  }
  int len=V/min;
  if(len==0){
    printf("-1\n");
    return 0;
  }
  while(len-->0){
    for(int d=9;d>0;d--){
      if((V-as[d])>=min*len){
	printf("%d",d);
	V-=as[d];
	break;
      }
    }
  }
  printf("\n");
  return 0;
}