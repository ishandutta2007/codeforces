#include <cstdio>
#include <algorithm>

void solve(){
  int H,W;
  scanf("%d %d",&H,&W);
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(((i==0||i==H-1)&&(((j%2==0)&&(j<W-2))||(j==W-1)))||
	 ((j==0||j==W-1)&&(((i%2==0)&&(i<H-2))||(i==H-1)))){
	printf("1");
      }else{
	printf("0");
      }
    }
    printf("\n");
  }
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}