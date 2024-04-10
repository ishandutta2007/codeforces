#include <cstdio>
#include <cassert>

void solve(){
  int N;
  scanf("%d",&N);
  long long x=0,s=0;
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    x^=A;
    s+=A;
  }
  long long ans=0;
  for(int k=0;k<60;k++){
    if((((s+ans)^((x^ans)<<1))>>k)&1){
      ans^=(1LL<<k);
    }
  }
  assert((s+ans)==((x^ans)<<1));
  printf("1\n");
  printf("%lld\n",ans);
}
  
int main(){
  int T;
  scanf("%d",&T);
  while(T--){
   solve();
  }
}