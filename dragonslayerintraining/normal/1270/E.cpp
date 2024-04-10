#include <cstdio>

int xs[1000005];
int ys[1000005];

int parity(int i){
  return ((xs[i]+ys[i])%2+2)%2;
}

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d %d",&xs[i],&ys[i]);
  }
  while(true){
    int cnt[2]={0,0};
    for(int i=0;i<N;i++){
      cnt[parity(i)]++;
    }
    if(cnt[0]&&cnt[1]){
      printf("%d\n",cnt[1]);
      for(int i=0;i<N;i++){
	if(parity(i)){
	  printf("%d ",i+1);
	}
      }
      printf("\n");
      return 0;
    }else{
      if(cnt[1]){
	for(int i=0;i<N;i++){
	  xs[i]++;
	}
      }
      for(int i=0;i<N;i++){
	int a=(xs[i]+ys[i])/2;
	int b=(xs[i]-ys[i])/2;
	xs[i]=a;
	ys[i]=b;
      }
    }
  }
}