#include <cstdio>
#include <vector>
#include <bitset>

struct Range{
  int L,R,X;
  Range(int L,int R,int X):L(L),R(R),X(X){
  }
};

int N;

std::bitset<10001> dfs(int L,int R,const std::vector<struct Range>& ranges){
  int M=(L+R)/2;
  std::vector<int> cover;
  for(auto range:ranges){
    if(range.L<=L&&range.R>=R){
      cover.push_back(range.X);
      continue;
    }
  }
  std::bitset<10001> res;
  if(R-L==1){
    res[0]=1;
  }else{
    std::vector<struct Range> left,right;
    for(auto range:ranges){
      if(range.L<=L&&range.R>=R){
	continue;
      }
      if(range.L<M){
	left.push_back(range);
      }
      if(range.R>=M){
	right.push_back(range);
      }
    }
    res=dfs(L,M,left)|dfs(M,R,right);
  }
  for(int cvr:cover){
    res|=(res<<cvr);
  }
  return res;
}

int main(){
  int Q;
  scanf("%d %d",&N,&Q);
  std::vector<struct Range> ranges;
  for(int i=0;i<Q;i++){
    int L,R,X;
    scanf("%d %d %d",&L,&R,&X);
    L--;
    ranges.emplace_back(L,R,X);
  }
  std::bitset<10001> bitset=dfs(0,N,ranges);
  std::vector<int> vs;
  for(int i=1;i<=N;i++){
    if(bitset[i]){
      vs.push_back(i);
    }
  }
  printf("%d\n",(int)vs.size());
  for(int i=0;i<vs.size();i++){
    if(i) printf(" ");
    printf("%d",vs[i]);
  }
  printf("\n");
  return 0;
}