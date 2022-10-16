#include <cstdio>
#include <algorithm>

void output(int x,int y){
  printf("%d %d\n",x+1,y+1);
}

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int dist=0;2*dist<=N+M-2;dist++){
    if(2*dist==N+M-2){
      for(int i=std::max(0,dist-M+1);i*2<=N-1;i++){
	int j=dist-i;
	output(i,j);
	if(i*2!=N-1){
	  output(N-1-i,M-1-j);
	}
      }
    }else{
      for(int i=std::max(0,dist-M+1);i<=std::min(N-1,dist);i++){
	int j=dist-i;
	output(i,j);
	output(N-1-i,M-1-j);
      }
    }
  }
  return 0;
}