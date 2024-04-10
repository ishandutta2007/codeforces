#include <cstdio>
#include <algorithm>
#include <chrono>
#include <random>

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
int as[200005];
bool got[200005];
std::vector<int> from[200005];
int to[200005];

void solve(){
  int N;
  scanf("%d",&N);
  std::fill(got+1,got+N+1,false);
  std::fill(from+1,from+N+1,std::vector<int>());
  for(int i=1;i<=N;i++){
    scanf("%d",&as[i]);
    got[as[i]]=true;
    from[as[i]].push_back(i);
  }
  int K=std::count(got+1,got+N+1,true);
  while(true){
    std::vector<int> unused;
    std::fill(to+1,to+N+1,0);
    for(int i=1;i<=N;i++){
      if(got[i]){
	int j=from[i][std::uniform_int_distribution<int>(0,from[i].size()-1)(rng)];
	to[j]=i;
      }else{
	unused.push_back(i);
      }
    }
    std::shuffle(unused.begin(),unused.end(),rng);
    for(int i=1;i<=N;i++){
      if(to[i]==0){
	to[i]=unused.back();
	unused.pop_back();
      }
    }
    bool bad=false;
    for(int i=1;i<=N;i++){
      if(to[i]==i){
	bad=true;
      }
    }
    if(!bad) break;
  }
  printf("%d\n",K);
  for(int i=1;i<=N;i++){
    printf("%d",to[i]);
    if(i==N){
      printf("\n");
    }else{
      printf(" ");
    }
  }
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}