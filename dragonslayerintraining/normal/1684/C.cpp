#include <cstdio>
#include <algorithm>
#include <vector>


void solve(){
  int N,M;
  scanf("%d %d",&N,&M);
  std::vector<std::vector<int>> as(N,std::vector<int>(M));
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      scanf("%d",&as[i][j]);
    }
  }
  auto bs=as;
  for(int i=0;i<N;i++){
    std::sort(bs[i].begin(),bs[i].end());
    for(int j=0;j<M;j++){
      if(as[i][j]!=bs[i][j]){
	for(int k=j+1;j<M;k++){
	  if(as[i][k]!=bs[i][k]){
	    for(int l=0;l<N;l++){
	      std::swap(as[l][j],as[l][k]);
	    }
	    for(int r=0;r<N;r++){
	      if(!std::is_sorted(as[r].begin(),as[r].end())){
		printf("-1\n");
		return;
	      }
	    }
	    printf("%d %d\n",j+1,k+1);
	    return;
	  }
	}
      }
    }
  }
  printf("1 1\n");
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}