#include <cstdio>

int N;
int as[100];

int main(){
  int maj=0;
  int cnt=0;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
    if(as[i]==maj){
      cnt++;
    }else if(cnt==0){
      maj=as[i];
      cnt++;
    }else{
      cnt--;
    }
  }
  cnt=0;
  for(int i=0;i<N;i++){
    if(as[i]==maj){
      cnt++;
    }
  }
  if(cnt<=(N+1)/2){
    printf("YES\n");
  }else{
    printf("NO\n");
  }
  return 0;
}