#include <cstdio>

int as[200005];
int bs[200005];
int ok[400005];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
    if(as[i]){
      ok[N+1-as[i]]++;
    }
  }
  for(int i=0;i<N;i++){
    scanf("%d",&bs[i]);
    if(bs[i]){
      int start=i+1-bs[i];
      if(start>=0){
	ok[start]++;
	ok[start+1]--;
      }
      ok[i+N+2-bs[i]]++;
    }
  }
  int sum=0;
  for(int i=0;i<=N*2;i++){
    sum+=ok[i];
    if(sum==N){
      printf("%d\n",i);
      return 0;
    }
  }
  return 0;
}