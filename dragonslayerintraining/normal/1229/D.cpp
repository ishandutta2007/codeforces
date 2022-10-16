#include <cstdio>
#include <stdint.h>
#include <algorithm>
#include <bitset>
#include <unordered_map>
#include <vector>


int8_t compose[120][120];

std::vector<int> expand[120];

int64_t total=0;

int K,KF=1;

void dump_perm(int i){
  for(int k=0;k<K;k++){
    printf("%d ",expand[i][k]);
  }
}

int compress(std::vector<int> p){
  int id=0;
  for(int i=0;i<p.size();i++){
    int index=0;
    for(int j=0;j<i;j++){
      if(p[j]>p[i]){
	index++;
      }
    }
    id=id*(i+1)+index;
  }
  return id;
}

void init_compose(){
  std::vector<int> ps,qs;
  for(int i=0;i<K;i++){
    ps.push_back(i);
    qs.push_back(i);
  }
  do{
    expand[compress(ps)]=ps;
    do{
      std::vector<int> rs(K);
      for(int i=0;i<K;i++){
	rs[i]=ps[qs[i]];
      }
      compose[compress(ps)][compress(qs)]=compress(rs);
    }while(std::next_permutation(qs.begin(),qs.end()));
  }while(std::next_permutation(ps.begin(),ps.end()));
  /*
  for(int i=0;i<KF;i++){
    for(int j=0;j<KF;j++){
      printf("compose["),dump_perm(i),printf("]["),dump_perm(j),printf("]="),dump_perm(compose[i][j]),printf("\n");
    }
  }
  */
}

std::bitset<120> complete(std::bitset<120> group,int p){
  static std::unordered_map<std::bitset<120>,std::unordered_map<int,std::bitset<120> > > memo;
  if(memo[group].count(p)){
    return memo[group][p];
  }
  std::bitset<120> init=group;
  while(true){
    std::bitset<120> next=group;
    for(int i=0;i<KF;i++){
      if(group.test(i)){
	for(int j=0;j<KF;j++){
	  if(group.test(j)){
	    next.set(compose[i][compose[p][j]]);
	  }
	}
      }
    }
    if(next==group) return memo[init][p]=group;
    group=next;
  }
}

int ps[200005];

int main(){
  int N;
  scanf("%d %d",&N,&K);
  for(int i=1;i<=K;i++){
    KF*=i;
  }
  init_compose();
  for(int i=0;i<N;i++){
    std::vector<int> tmp(K);
    for(int k=0;k<K;k++){
      scanf("%d",&tmp[k]);
    }
    ps[i]=compress(tmp);
    //printf("ps[%d]=%d\n",i,ps[i]);
  }
  std::bitset<120> identity;
  identity.set(0);
  
  std::unordered_map<std::bitset<120>,int> cnt;
  for(int i=0;i<N;i++){
    cnt[identity]++;
    std::unordered_map<std::bitset<120>,int> next;
    for(auto it:cnt){
      next[complete(it.first,ps[i])]+=it.second;
    }
    cnt=next;

    for(auto it:cnt){
      total+=it.second*it.first.count();
      //printf("i=%d cnt=%d:\n",i,it.second);
      /*
      for(int i=0;i<KF;i++){
	if(it.first.test(i)){
	  dump_perm(i),printf("\n");
	}
      }
      */
    }
  }
  printf("%I64d\n",total);
}