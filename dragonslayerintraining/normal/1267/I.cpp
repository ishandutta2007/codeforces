#include <cstdio>
#include <vector>
#include <algorithm>

bool less(int a,int b){
  printf("? %d %d\n",a+1,b+1);
  fflush(stdout);
  char c;
  scanf(" %c",&c);
  return c=='<';
}

void solve(){
  int N;
  scanf("%d",&N);
  int a=0,b=1;//know a>b
  if(less(a,b)) std::swap(a,b);
  int c=2;
  for(int i=3;i<N*2;i++){
    int d=i;//know c>d
    if(less(c,d)) std::swap(c,d);
    if(less(b,d)){
      std::swap(a,c);
      std::swap(b,d);
    }
    //know b>d
    //d is not top three
  }
  //a,b,c are top three in unknown order
  std::vector<int> rest;
  for(int i=0;i<N*2;i++){
    if(i!=a&&i!=b&&i!=c){
      for(int j=i+1;j<N*2;j++){
	if(j!=a&&j!=b&&j!=c){
	  less(i,j);
	}
      }
    }
  }
  printf("!\n");
  fflush(stdout);
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}