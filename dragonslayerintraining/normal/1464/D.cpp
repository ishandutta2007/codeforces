#include <cstdio>
#include <cassert>
#include <array>

const int MOD=1e9+7;
const int INF=1e9+7;

int ps[1000006];
bool vis[1000006];

//0,+2,+2+2
int score1(int N,int cycles,std::array<int,3> freq){
  int extra=N*2%3;//target # groups of +2
  int merges=0;
  while(freq[2]<extra){
    assert(extra==2||freq[1]>=2);
    if(freq[1]<2){
      return INF;
    }
    freq[1]-=2;
    freq[2]++;
    merges++;
  }
  freq[2]-=extra;
  while(freq[1]>0&&freq[2]>0){
    freq[1]--;
    freq[2]--;
    merges++;
  }
  while(freq[1]>=3){
    freq[1]-=3;
    merges+=2;
  }
  while(freq[2]>=3){
    freq[2]-=3;
    merges+=2;
  }
  assert(freq[1]==0&&freq[2]==0);
  int target_cycles=(N-2*extra)/3+extra;
  int splits=target_cycles+merges-cycles;
  int cost=merges+splits;
  return cost;
}

//+4
int score2(int N,int cycles,std::array<int,3> freq,bool four){
  int merges=0;
  if(freq[1]>0){
    freq[1]--;
    if(!four){
      if(freq[0]<1){
	return INF;
      }
      merges++;
    }
  }else{
    return INF;
  }
  while(freq[1]>0&&freq[2]>0){
    freq[1]--;
    freq[2]--;
    merges++;
  }
  while(freq[1]>=3){
    freq[1]-=3;
    merges+=2;
  }
  while(freq[2]>=3){
    freq[2]-=3;
    merges+=2;
  }
  assert(freq[1]==0&&freq[2]==0);
  int target_cycles=(N-4)/3+1;
  int splits=target_cycles+merges-cycles;
  int cost=merges+splits;
  return cost;
}

void solve(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&ps[i]);
    ps[i]--;
  }
  std::fill(vis,vis+N,false);
  int cycles=0;
  std::array<int,3> ofreq={0,0,0};
  bool four=false;
  for(int i=0;i<N;i++){
    if(!vis[i]){
      int len=0;
      for(int j=i;!vis[j];j=ps[j]){
	vis[j]=true;
	len++;
      }
      cycles++;
      ofreq[len%3]++;
      if(len%3==1&&len>=4){
	four=true;
      }
    }
  }
  int best=score1(N,cycles,ofreq);
  //+4
  if(N%3==1){
    best=std::min(best,score2(N,cycles,ofreq,four));
  }
  int score=1;
  while(N>4){
    N-=3;
    score=score*3LL%MOD;
  }
  printf("%lld %d\n",1LL*score*N%MOD,best);
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}