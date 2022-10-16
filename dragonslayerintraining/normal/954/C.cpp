#include <cstdio>
#include <numeric>
#include <cmath>

int as[200000];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
    as[i]--;
  }
  int y=1;
  for(int i=1;i<N;i++){
    int d=std::abs(as[i-1]-as[i]);
    if(d==0){
      printf("NO\n");
      return 0;
    }
    if(d!=1){
      if(y==1){
	y=d;
      }else if(y!=d){
	printf("NO\n");
	return 0;
      }
    }
  }
  for(int i=1;i<N;i++){
    if(std::abs(as[i]%y-as[i-1]%y)+std::abs(as[i]/y-as[i-1]/y)!=1){
      printf("NO\n");
      return 0;
    }
  }
  printf("YES\n%d %d\n",(int)1e9,y);
  return 0;
}