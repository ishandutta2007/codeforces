#include <cstdio>
#include <vector>
#include <cstring>

char str[500005];

void solve(){
  scanf("%s",str);
  int N=strlen(str);
  std::vector<int> up(N*2);
  std::vector<int> down(N*2);
  int level=N;
  for(int i=0;i<N;i++){
    if(str[i]=='0'){
      down[level--]++;
    }else{
      up[level++]++;
    }
  }
  level=N;
  for(int i=0;i<N;i++){
    if((down[level]&&up[level-1])||!up[level]){
      printf("0");
      down[level--]--;
    }else{
      printf("1");
      up[level++]--;
    }
  }
  printf("\n");
}
  
int main(){
  int T;
  scanf("%d",&T);
  for(int t=0;t<T;t++){
    solve();
  }
}