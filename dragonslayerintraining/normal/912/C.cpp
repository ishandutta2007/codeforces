#include <cstdio>
#include <algorithm>
#include <stdint.h>
#include <map>
#include <vector>

const int64_t INF=1e18+7;

int64_t bounty,increase,damage;

struct Enemy{
  int64_t max_health,regen;
  //pair<time,health>
  std::vector<std::pair<int64_t,int64_t> > updates;
}enemies[100000];

std::map<int64_t,int64_t> prefix;

int main(){
  int64_t N,M;
  scanf("%I64d %I64d",&N,&M);
  scanf("%I64d %I64d %I64d",&bounty,&increase,&damage);
  for(int64_t i=0;i<N;i++){
    int64_t start_health;
    scanf("%I64d %I64d %I64d",&enemies[i].max_health,&start_health,&enemies[i].regen);
    enemies[i].updates.emplace_back(0,start_health);
  }
  for(int64_t i=0;i<M;i++){
    int64_t time,enemy,health;
    scanf("%I64d %I64d %I64d",&time,&enemy,&health);
    enemy--;
    enemies[enemy].updates.emplace_back(time,health);
  }
  for(int64_t i=0;i<N;i++){
    if(enemies[i].max_health<=damage){
      prefix[0]++;
    }else{
      std::sort(enemies[i].updates.begin(),enemies[i].updates.end());
      int64_t prev=0;
      int64_t expire=INF;
      for(auto update:enemies[i].updates){
	int64_t time=update.first;
	int64_t health=update.second;
	prefix[std::min(time,expire)]-=prev;
	prev=0;
	expire=INF;
	if(health<=damage){
	  prefix[time]++;
	  prev=1;
	  if(enemies[i].regen>0){
	    expire=time+(damage-health+enemies[i].regen)/enemies[i].regen;
	  }
	}
      }
      if(expire<INF){
	prefix[expire]-=prev;
      }
    }
  }
  int64_t sum=0;
  int64_t best=0;
  for(auto pair:prefix){
    int64_t time=pair.first;
    int64_t delta=pair.second;
    best=std::max(best,sum*(bounty+(time-1)*increase));
    sum+=delta;
  }
  if(sum>0){
    if(increase==0){
      best=std::max(best,sum*bounty);
    }else{
      best=-1;
    }
  }
  printf("%I64d\n",best);
  return 0;
}