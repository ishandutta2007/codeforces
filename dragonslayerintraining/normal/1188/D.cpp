#include <cstdio>
#include <vector>
#include <map>
#include <cassert>
#include <algorithm>

int64_t cycle_mod(int64_t x,int64_t m){
  return (x%m+m)%m;
}

//2^58 -> 2^0

std::vector<std::pair<int64_t,int64_t> > cost;
int64_t as[1000005];

void dump(int64_t k){
  printf("k=%I64d\n",k);
  for(auto it:cost){
    printf(" %I64d:%I64d\n",it.first,it.second);
  }
  printf("\n");
}

int main(){
  int64_t N;
  scanf("%I64d",&N);
  for(int64_t i=0;i<N;i++){
    scanf("%I64d",&as[i]);
  }
  int64_t max=*std::max_element(as,as+N);
  for(int64_t i=0;i<N;i++){
    as[i]=as[i]-max;
  }
  //Reduce from 2^k to 2^(k-1)
  cost.push_back({0,0});
  for(int64_t k=60;k>=1;k--){
    cost.push_back({1LL<<(k-1),0});
    
    //dump(k);
    
    for(int64_t i=0;i<N;i++){
      int64_t b=cycle_mod(as[i],1LL<<k);
      int64_t a=cycle_mod(as[i]+(1LL<<(k-1)),1LL<<k);
      cost.push_back({a,1});
      cost.push_back({b,-1});
      if(a>b) cost.push_back({0,1});
    }

    std::sort(cost.begin(),cost.end());
    {
      std::vector<std::pair<int64_t,int64_t> > tmp;
      for(auto it:cost){
	if(tmp.empty()||tmp.back().first!=it.first){
	  tmp.push_back({it.first,0});
	}
	tmp.back().second+=it.second;
      }
      std::swap(tmp,cost);
    }
    //dump(k);
    
    {
      int64_t prefix=0;
      for(auto& it:cost){
	prefix+=it.second;
	it.second=prefix;
      }
    }

    std::vector<std::pair<int64_t,int64_t> > next;

    assert(next.size()%2==0);
    for(int i=0;i<cost.size()/2;i++){
      assert(cost[i].first==cost[i+cost.size()/2].first%(1LL<<(k-1)));
      if(k!=60){
	next.push_back({cost[i].first,std::min(cost[i].second,cost[i+cost.size()/2].second)});
      }else{
	next.push_back(cost[i]);
      }
    }
    std::swap(cost,next);

    //dump(k);
    
    {
      int64_t prev=0;
      for(auto& it:cost){
	int64_t curr=it.second;
	it.second=curr-prev;
	prev=curr;
      }
    }
  }
  //printf("Final\n");
  //dump(-1);
  assert(cost.size()==1);
  printf("%I64d\n",cost[0].second);
  return 0;
}