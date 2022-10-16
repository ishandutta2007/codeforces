#include <cstdio>
#include <vector>
#include <tuple>
#include <cassert>

int N,K;

int road[100];
int park[100];

std::vector<std::tuple<int,int,int> > moves;

void output_park(int i,int c){
  if(!i) return;
  if(c<N){
    moves.emplace_back(i,1,c+1);
  }else{
    moves.emplace_back(i,4,N*2-c);
  }
}

void output_road(int i,int c){
  if(!i) return;
  if(c<N){
    moves.emplace_back(i,2,c+1);
  }else{
    moves.emplace_back(i,3,N*2-c);
  }
}

int main(){
  scanf("%d %d",&N,&K);
  for(int i=0;i<N;i++){
    scanf("%d",&park[i]);
  }
  for(int i=0;i<N;i++){
    scanf("%d",&road[i]);
  }
  for(int i=0;i<N;i++){
    scanf("%d",&road[N*2-1-i]);
  }
  for(int i=0;i<N;i++){
    scanf("%d",&park[N*2-1-i]);
  }
  for(int t=0;t<N*2;t++){
    for(int i=0;i<N*2;i++){
      if(road[i]&&road[i]==park[i]){
	output_park(park[i],i);
	road[i]=0;
      }
    }
    int open=-1;
    for(int i=0;i<N*2;i++){
      if(!road[i]) open=i;
    }
    if(open==-1){
      printf("-1\n");
      return 0;
    }
    for(int i=0;i<N*2-1;i++){
      int j=(i+open)%(N*2);
      int k=(i+open+1)%(N*2);
      output_road(road[k],j);
      assert(road[j]==0);
      road[j]=road[k];
      road[k]=0;
    }
  }
  printf("%d\n",(int)moves.size());
  for(auto move:moves){
    printf("%d %d %d\n",std::get<0>(move),std::get<1>(move),std::get<2>(move));
  }
  return 0;
}