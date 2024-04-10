#include <cstdio>
#include <vector>
#include <array>
#include <cassert>

const bool debug=false;

int triple[1<<12][3];

int use[1<<12];
int cost[1<<12];

std::vector<int> gen_masks(int L){
  std::vector<int> masks;
  masks.push_back(0);
  for(int i=0;i<L;i++){
    for(int j=1;j<L;j++){
      if(i+j*2>=L) continue;
      masks.push_back((1<<i)|(1<<(i+j))|(1<<(i+2*j)));
    }
  }
  return masks;
}

int as[100005];

int main(){
  std::vector<int> masks=gen_masks(12);
  for(int u:masks){
    for(int v:masks){
      for(int w:masks){
	int res=(u^v^w)&((1<<9)-1);
	triple[res][0]=u;
	triple[res][1]=v;
	triple[res][2]=w;
      }
    }
  }
  std::vector<std::array<int,3> > moves;
  int NN;
  scanf("%d",&NN);
  int N=NN;
  for(int i=1;i<=N;i++){
    scanf("%d",&as[i]);
  }
  while(N>=12){
    int M=0;
    for(int i=0;i<9;i++){
      M|=(as[N-i]<<i);
    }
    for(int t=0;t<3;t++){
      std::array<int,3> move;
      int index=0;
      for(int i=0;i<12;i++){
	if(triple[M][t]&(1<<i)){
	  as[N-i]^=1;
	  move[index++]=N-i;
	}
      }
      if(index){
	assert(index==3);
	moves.push_back(move);
      }
    }
    N-=9;
  }
  N=std::min(NN,12);
  masks=gen_masks(N);
  for(int i=1;i<(1<<N);i++){
    cost[i]=1e9;
  }
  for(int mask:masks){
    for(int i=0;i<(1<<N);i++){
      if(cost[i^mask]>cost[i]+1){
	cost[i^mask]=cost[i]+1;
	use[i^mask]=mask;
      }
    }
  }
  if(debug){
    int worst=0;
    for(int i=0;i<(1<<N);i++){
      if(cost[i]<1e9) worst=std::max(worst,cost[i]);
      printf("%d: ",i);
      for(int k=0;k<N;k++){
	printf("%d",(use[i]>>k)&1);
      }
      printf("\n");
    }
    printf("WORST: %d\n",worst);
  }
  while(true){
    int M=0;
    for(int i=0;i<N;i++){
      M|=(as[N-i]<<i);
    }
    if(M==0) break;
    std::array<int,3> move;
    int index=0;
    for(int i=0;i<12;i++){
      if(use[M]&(1<<i)){
	as[N-i]^=1;
	move[index++]=N-i;
      }
    }
    if(index==0){
      printf("NO\n");
      return 0;
    }
    assert(index==3);
    moves.push_back(move);
  }
  for(int i=0;i<N;i++){
    assert(as[i]==0);
  }
  printf("YES\n");
  printf("%d\n",(int)moves.size());
  for(auto move:moves){
    printf("%d %d %d\n",move[0],move[1],move[2]);
  }
  return 0;
}