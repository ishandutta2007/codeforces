#include <cstdio>
#include <algorithm>
#include <vector>

int ps[300005];
int shift[300005];
int qs[300005];

bool vis[300005];
int N,M;

int cost(){
  std::fill(vis,vis+N,false);
  int cycles=0;
  for(int i=0;i<N;i++){
    if(vis[i]) continue;
    int j=i;
    do{
      vis[j]=true;
      j=qs[j];
    }while(j!=i);
    cycles++;
  }
  return N-cycles;
}

void solve(){
  scanf("%d %d",&N,&M);
  for(int i=0;i<N;i++){
    scanf("%d",&ps[i]);
    ps[i]--;
  }
  std::fill(shift,shift+N,0);
  for(int i=0;i<N;i++){
    shift[(i-ps[i]+N)%N]++;
  }
  std::vector<int> ans;
  for(int s=0;s<N;s++){
    if(shift[s]>=N-2*M){
      //printf("s=%d: ",s);
      for(int i=0;i<N;i++){
	qs[i]=(ps[i]+s)%N;
	//printf(" %d",qs[i]);
      }
      //printf(": %d\n",cost());
      if(cost()<=M){
	ans.push_back(s);
      }
    }
  }
  printf("%d",(int)ans.size());
  for(int x:ans){
    printf(" %d",x);
  }
  printf("\n");
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}