#include <cstdio>

int as[100005];
int cnt[2];

int main(){
  int N,Q;
  scanf("%d %d",&N,&Q);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
    cnt[as[i]]++;
  }
  for(int i=0;i<Q;i++){
    int T,X;
    scanf("%d %d",&T,&X);
    if(T==1){
      X--;
      cnt[as[X]]--;
      as[X]=1-as[X];
      cnt[as[X]]++;
    }else{
      if(cnt[1]>=X){
	printf("1\n");
      }else{
	printf("0\n");
      }
    }
  }
}