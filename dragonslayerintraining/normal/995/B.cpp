#include <cstdio>
#include <algorithm>

int as[500];

int cnt=0;

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N*2;i++){
    scanf("%d",&as[i]);
  }
  for(int i=0;i<N*2;i+=2){
    for(int j=i+1;j<N*2;j++){
      if(as[j]==as[i]){
	while(j>i+1){
	  cnt++;
	  std::swap(as[j],as[j-1]);
	  j--;
	}
	break;
      }
    }
  }
  printf("%d\n",cnt);
  return 0;
}