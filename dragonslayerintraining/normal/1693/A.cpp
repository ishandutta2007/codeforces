#include <cstdio>

long long as[200005];

bool solve(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%lld",&as[i]);
  }
  for(int i=1;i<N;i++){
    as[i]+=as[i-1];
  }
  if(as[N-1]!=0) return false;
  int i=0;
  while(i<N&&as[i]>0) i++;
  while(i<N&&as[i]==0) i++;
  return i==N;
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    if(solve()){
      printf("YES\n");
    }else{
      printf("NO\n");
    }
  }
}