#include <cstdio>
#include <algorithm>
#include <vector>

int N;
char lamps[200005];

int recolor[3][3];

const char colors[]="RGB";

int main(){
  scanf("%d %s",&N,lamps);
  for(int i=0;lamps[i];i++){
    for(int j=0;j<3;j++){
      if(lamps[i]!=colors[j]){
	recolor[i%3][j]++;
      }
    }
  }
  std::vector<int> ps{0,1,2};
  std::vector<int> best;
  int ans=N;
  do{
    int cost=recolor[0][ps[0]]+recolor[1][ps[1]]+recolor[2][ps[2]];
    if(cost<ans){
      ans=cost;
      best=ps;
    }
  }while(std::next_permutation(ps.begin(),ps.end()));
  printf("%d\n",ans);
  for(int i=0;i<N;i++){
    printf("%c",colors[best[i%3]]);
  }
  printf("\n");
}