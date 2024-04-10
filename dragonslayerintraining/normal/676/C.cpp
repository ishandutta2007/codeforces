#include <cstdio>
#include <algorithm>

char str[100000];
int best=0;
int N,K;

void check(){
  int j=0;
  int xs=0;
  for(int i=0;i<N;i++){
    xs+=(str[i]=='b');
    if(xs>K){
      xs-=(str[j++]=='b');
    }
    best=std::max(best,i-j+1);
  }
}

int main(){
  scanf("%d %d",&N,&K);
  scanf("%s",str);
  check();
  for(int i=0;i<N;i++){
    str[i]^=('a'^'b');
  }
  check();
  printf("%d\n",best);
  return 0;
}