#include <cstdio>
#include <set>
#include <algorithm>

const long long INF=1e18+7;

long long as[200005];
long long bs[200005];
long long ts[200005];
long long state[200005];

std::multiset<long long> slow;//wait for ai, plus ti
std::multiset<long long> fast;//plus ti
std::multiset<std::pair<long long,long long> > events;//(time,id)

void update(long long i){
  switch(state[i]++){
  case 0:
    slow.insert(as[i]+ts[i]);
    break;
  case 1:
    slow.erase(slow.find(as[i]+ts[i]));
    fast.insert(ts[i]);
    break;
  case 2:
    fast.erase(fast.find(ts[i]));
    break;
  }
}

int main(){
  long long N;
  scanf("%lld",&N);
  for(long long i=0;i<N;i++){
    scanf("%lld %lld %lld",&as[i],&bs[i],&ts[i]);
    events.insert({as[i],i});
    events.insert({bs[i]-ts[i]+1,i});
    update(i);
  }
  long long swords=0;
  long long T=0;//current time
  while(slow.size()||fast.size()){
    while(events.size()&&events.begin()->first<=T){
      update(events.begin()->second);
      events.erase(events.begin());
    }
    long long t_slow=slow.empty()?INF:*slow.begin();
    long long t_fast=fast.empty()?INF:(*fast.begin()+T);
    long long t_event=events.empty()?INF:events.begin()->first;
    long long t_min=std::min(t_slow,t_fast);
    long long t_swap=INF;
    if(slow.size()&&fast.size()){
      t_swap=*slow.begin()-*fast.begin();
      if(t_swap<=T) t_swap=INF;
    }
    long long t_change=std::min(t_event,t_swap);
    if(t_min==INF) break;
    if(t_min==t_slow){
      //printf("Slow sword");
      T=*slow.begin();
      swords++;
    }else if(t_min==t_fast){
      long long times=std::max(1LL,(t_change-T)/(*fast.begin()));
      //printf("Fast sword x%lld",times);
      swords+=times;
      T+=times*(*fast.begin());
      /*
      while(T<=t_change){
	T+=*fast.begin();
	swords++;
	printf("*");
      }
      */
    }
    //T=t_min;
    //printf("T=%lld\n",T);
  }
  printf("%lld\n",swords);
}