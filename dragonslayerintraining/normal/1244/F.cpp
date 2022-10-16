#include <cstdio>
#include <algorithm>

const int INF=1e9+7;

char str[200005];
int freeze[200005];

int main(){
  int N,K;
  scanf("%d %d",&N,&K);
  scanf("%s",str);
  for(int i=0;i<N;i++){
    if(str[i]==str[(i+1)%N]||str[i]==str[(i+N-1)%N]){
      freeze[i]=0;
    }else{
      freeze[i]=INF;
    }
  }
  for(int i=1;i<N*2;i++){
    freeze[i%N]=std::min(freeze[i%N],freeze[(i-1)%N]+1);
  }
  for(int i=N*2;i>0;i--){
    freeze[i%N]=std::min(freeze[i%N],freeze[(i+1)%N]+1);
  }
  for(int i=0;i<N;i++){
    putchar(str[i]^((std::min(K,freeze[i])&1)*('B'^'W')));
  }
  putchar('\n');
}