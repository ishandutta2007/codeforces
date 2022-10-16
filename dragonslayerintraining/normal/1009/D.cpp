#include <cstdio>
#include <vector>
#include <cstdlib>

int gcd(int a,int b){
  return b?gcd(b,a%b):a;
}

std::vector<std::pair<int,int> > edges;

void finish(){
  printf("Possible\n");
  for(auto e:edges){
    printf("%d %d\n",e.first,e.second);
  }
  exit(0);
}

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  if(M<N-1){
    printf("Impossible\n");
    return 0;
  }
  for(int i=1;i<N;i++){
    for(int j=i+1;j<=N;j++){
      if(gcd(i,j)>1) continue;
      edges.emplace_back(i,j);
      if(edges.size()==M){
	finish();
      }
    }
  }
  printf("Impossible\n");
  return 0;
}