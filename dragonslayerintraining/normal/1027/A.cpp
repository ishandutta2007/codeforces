#include <cstdio>

char str[1000];

void solve(){
  int N;
  scanf("%d %s",&N,str);
  for(int i=0;i<N;i++){
    int diff=str[i]-str[N-1-i];
    if(diff!=-2&&diff!=0&&diff!=2){
      printf("NO\n");
      return;
    }
  }
  printf("YES\n");
}

int main(){
  int T;
  scanf("%d",&T);
  while(T-->0){
    solve();
  }
  return 0;
}