#include <cstdio>
#include <vector>
#include <set>
#include <cassert>
#include <algorithm>

bool fort[100005];
std::vector<int> adj[100005];
bool own[100005];
int power[100005];

std::set<std::pair<double,int> > strength;

void lose(int x){
  assert(own[x]);
  own[x]=false;
  for(int y:adj[x]){
    if(own[y]){
      strength.erase({(double)power[y]/adj[y].size(),y});
      power[y]--;
      strength.insert({(double)power[y]/adj[y].size(),y});
    }
  }
}

int main(){
  int N,M,K;
  scanf("%d %d %d",&N,&M,&K);
  for(int i=0;i<K;i++){
    int F;
    scanf("%d",&F);
    F--;
    fort[F]=true;
  }
  for(int i=0;i<M;i++){
    int A,B;
    scanf("%d %d",&A,&B);
    A--,B--;
    adj[A].push_back(B);
    adj[B].push_back(A);
  }
  for(int i=0;i<N;i++){
    if(!fort[i]){
      own[i]=true;
    }
  }
  for(int i=0;i<N;i++){
    if(!own[i]) continue;
    for(int j:adj[i]){
      if(own[j]){
	power[i]++;
      }
    }
    strength.insert({(double)power[i]/adj[i].size(),i});
  }
  double best=-1;
  while(strength.size()>0){
    auto pair=*strength.begin();
    strength.erase(strength.begin());
    best=std::max(best,pair.first);
    lose(pair.second);
  }
  assert(strength.empty());
  std::fill(power,power+N,0);
  assert(std::count(own,own+N,false)==N);
  //fprintf(stderr,"best=%.10lf\n",best);
  for(int i=0;i<N;i++){
    if(!fort[i]){
      own[i]=true;
    }
  }
  for(int i=0;i<N;i++){
    if(!own[i]) continue;
    for(int j:adj[i]){
      if(own[j]){
	power[i]++;
      }
    }
    strength.insert({(double)power[i]/adj[i].size(),i});
  }
  while(strength.size()>0){
    auto pair=*strength.begin();
    strength.erase(strength.begin());
    //fprintf(stderr,"best=%.10lf, curr=%.10lf\n",best,pair.first);
    if(best==pair.first){
      printf("%d\n",(int)std::count(own,own+N,true));
      for(int i=0;i<N;i++){
	if(own[i]){
	  printf("%d ",i+1);
	}
      }
      printf("\n");
      return 0;
    }
    lose(pair.second);
  }
}