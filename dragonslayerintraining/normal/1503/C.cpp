#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>

const long long INF=1e15;

struct City{
  int a,c;
  bool operator<(City other)const{
    return a<other.a;
  }
}cities[100005];
int as[100005];
int cs[100005];

struct Event{
  int x;
  int id;
  enum {LEFT,RIGHT} type;
};

long long dp[100005];

int main(){
  int N;
  scanf("%d",&N);
  std::vector<Event> evs;
  for(int i=0;i<N;i++){
    scanf("%d %d",&cities[i].a,&cities[i].c);
  }
  std::sort(cities,cities+N);
  for(int i=0;i<N;i++){
    as[i]=cities[i].a;
    cs[i]=cities[i].c;
  }
  for(int i=0;i<N;i++){
    evs.push_back({as[i],i,Event::LEFT});
    evs.push_back({as[i]+cs[i],i,Event::RIGHT});
  }
  std::stable_sort(evs.begin(),evs.end(),[](Event a,Event b){return a.x<b.x;});
  std::multiset<long long> left,right;
  left.insert(INF);
  right.insert(INF);
  for(Event e:evs){
    int i=e.id;
    if(e.type==Event::LEFT){
      if(i==0){
	dp[i]=0;
      }else{
	dp[i]=std::min(*left.begin()+as[i],*right.begin());
      }
      //printf("dp[%d]=%lld\n",i,dp[i]);
      right.insert(dp[i]);
    }else{
      right.erase(right.find(dp[i]));
      left.insert(dp[i]-as[i]-cs[i]);
    }
  }
  long long total=dp[N-1];
  for(int i=0;i<N;i++){
    total+=cs[i];
  }
  printf("%lld\n",total);
}