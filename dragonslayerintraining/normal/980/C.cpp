#include <cstdio>
#include <algorithm>

int pix[256];
int opt[256];

int main(){
  int N,K;
  std::fill(pix,pix+256,-1);
  std::fill(opt,opt+256,-1);
  scanf("%d %d",&N,&K);
  for(int i=0;i<N;i++){
    int P;
    scanf("%d",&P);
    if(i) printf(" ");
    if(pix[P]==-1){
      if(opt[P]>=0){
	for(int k=P;k>=0&&pix[k]==-1;k--){
	  pix[k]=opt[P];
	}
      }else{
	int key=P;
	while(key>=0&&key>P-K&&pix[key]==-1){
	  key--;
	}
	key++;
	std::fill(pix+key,pix+P+1,key);
	std::fill(opt+key,opt+std::min(256,key+K),key);
      }
    }
    printf("%d",pix[P]);
  }
  printf("\n");
  return 0;
}