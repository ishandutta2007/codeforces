#include <cstdio>
#include <vector>
#include <set>

int N,T;

std::vector<int> rem[200000];

int as[200000];
int ts[200000];

int main(){
  scanf("%d %d",&N,&T);
  for(int i=0;i<N;i++){
    int a,t;
    scanf("%d %d",&as[i],&ts[i]);
    rem[as[i]-1].push_back(i);
  }
  int opt=0;
  {
    std::set<std::pair<int,int> > solve;
    std::set<std::pair<int,int> > buffer;
    for(int i=0;i<N;i++){
      buffer.emplace(ts[i],i);
    }
    buffer.emplace(1e9+1,-1);
    for(int i=0;i<N;i++){
      while((solve.size()<=i)&&(T>=buffer.begin()->first)){
	T-=buffer.begin()->first;
	solve.insert(*buffer.begin());
	buffer.erase(buffer.begin());
      }
      opt=std::max<int>(opt,solve.size());
      for(int ri:rem[i]){
	if(buffer.count(std::make_pair(ts[ri],ri))){
	  buffer.erase(std::make_pair(ts[ri],ri));
	}else{
	  solve.erase(std::make_pair(ts[ri],ri));
	  T+=ts[ri];
	}
      }
    }
  }
  {
    std::set<std::pair<int,int> > solve;
    std::set<std::pair<int,int> > buffer;
    for(int i=0;i<N;i++){
      buffer.emplace(ts[i],i);
    }
    buffer.emplace(1e9+1,-1);
    for(int i=0;i<N;i++){
      while((solve.size()<=i)&&(T>=buffer.begin()->first)){
	T-=buffer.begin()->first;
	solve.insert(*buffer.begin());
	buffer.erase(buffer.begin());
      }
      if(solve.size()==opt){
	printf("%d\n%d\n",opt,opt);
	for(std::pair<int,int> pair:solve){
	  if(pair!=*solve.begin()){
	    printf(" ");
	  }
	  printf("%d",pair.second+1);
	}
	printf("\n");
	return 0;
      }
      for(int ri:rem[i]){
	if(buffer.count(std::make_pair(ts[ri],ri))){
	  buffer.erase(std::make_pair(ts[ri],ri));
	}else{
	  solve.erase(std::make_pair(ts[ri],ri));
	  T+=ts[ri];
	}
      }
    }
  }
  return 0;
}