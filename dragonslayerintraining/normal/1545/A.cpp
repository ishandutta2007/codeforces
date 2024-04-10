#include <cstdio>
#include <algorithm>

int as[2][100005];
int bs[100005];

void solve(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i%2][i/2]);
  }
  std::sort(as[0],as[0]+(N+1)/2);
  std::sort(as[1],as[1]+N/2);
  for(int i=0;i<N;i++){
    bs[i]=as[i%2][i/2];
  }
  if(std::is_sorted(bs,bs+N)){
    printf("YES\n");
  }else{
    printf("NO\n");
  }
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}