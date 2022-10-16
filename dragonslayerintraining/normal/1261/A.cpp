#include <cstdio>
#include <algorithm>
#include <vector>

char str[2005];
char target[2005];

void solve(){
  int N,K;
  scanf("%d %d",&N,&K);
  scanf("%s",str);
  for(int i=0;i<2*(K-1);i+=2){
    target[i]='(';
    target[i+1]=')';
  }
  int run=(N-2*(K-1))/2;
  for(int i=0;i<run;i++){
    target[2*(K-1)+i]='(';
    target[2*(K-1)+run+i]=')';
  }
  /*
  fprintf(stderr,"str   : %s\n",str);
  target[N]='\0';
  fprintf(stderr,"Target: %s\n",target);
  */
  std::vector<std::pair<int,int> > moves;
  for(int i=0;i<N;i++){
    if(str[i]==target[i]) continue;
    for(int j=i+1;j<N;j++){
      if(target[i]==str[j]){
	moves.push_back({i,j});
	std::reverse(str+i,str+j+1);
	break;
      }
    }
  }
  printf("%d\n",(int)moves.size());
  for(auto m:moves){
    printf("%d %d\n",m.first+1,m.second+1);
  }
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}