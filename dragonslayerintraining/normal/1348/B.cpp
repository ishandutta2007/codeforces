#include <cstdio>
#include <set>

void solve(){
  int N,K;
  scanf("%d %d",&N,&K);
  std::set<int> distinct;
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    distinct.insert(A);
  }
  if(distinct.size()>K){
    printf("-1\n");
  }else{
    printf("%d\n",N*K);
    for(int i=0;i<N;i++){
      for(int x:distinct){
	printf("%d ",x);
      }
      for(int j=distinct.size();j<K;j++){
	printf("%d ",*distinct.begin());
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