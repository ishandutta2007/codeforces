#include <cstdio>
#include <map>

std::map<int,int> players;
std::map<int,int> cards;

int hs[505][5005];

int main(){
  int N,K;
  scanf("%d %d",&N,&K);
  for(int i=0;i<K*N;i++){
    int C;
    scanf("%d",&C);
    cards[C]++;
  }
  for(int i=0;i<N;i++){
    int F;
    scanf("%d",&F);
    players[F]++;
  }
  for(int i=1;i<=K;i++){
    scanf("%d",&hs[1][i]);
  }
  for(int j=2;j<=N;j++){
    for(int i=1;i<=5000;i++){
      for(int k=0;k<=i&&k<=K;k++){
	hs[j][i]=std::max(hs[j][i],hs[j-1][i-k]+hs[1][k]);
      }
    }
  }
  int total=0;
  for(auto p:players){
    total+=hs[p.second][std::min(cards[p.first],p.second*K)];
  }
  printf("%d\n",total);
  return 0;
}