#include <cstdio>
#include <algorithm>

int as[200005];
int bs[200005];


void solve(){
  int N,KA,KB;
  scanf("%d %d %d",&N,&KA,&KB);
  for(int i=0;i<KA;i++){
    scanf("%d",&as[i]);
  }
  for(int i=0;i<KB;i++){
    scanf("%d",&bs[i]);
  }
  if(*std::max_element(as,as+KA)>
     *std::max_element(bs,bs+KB)){
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