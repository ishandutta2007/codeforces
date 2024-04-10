#include <cstdio>
#include <algorithm>

int N,K;
char str[100005];

void solve(){
  scanf("%d %d %s",&N,&K,str);
  std::sort(str,str+N);
  if(str[0]!=str[K-1]){
    printf("%c\n",str[K-1]);
    return;
  }else if(str[K]!=str[N-1]){
    printf("%s\n",str+K-1);
  }else{
    printf("%c%s\n",str[0],str+N-(N-1)/K);
  }
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}