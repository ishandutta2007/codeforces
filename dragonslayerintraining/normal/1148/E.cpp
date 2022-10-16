#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cassert>
#include <tuple>

int N;
struct Stone{
  int s;
  int id;
  bool operator<(struct Stone other)const{
    return s<other.s;
  }
}stones[300005];
int ts[300005];

void fail(){
  printf("NO\n");
  exit(0);
}

std::vector<std::array<int,3> > ans;//(i,j,d)

int main(){
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&stones[i].s);
    stones[i].id=i;
  }
  for(int i=0;i<N;i++){
    scanf("%d",&ts[i]);
  }
  std::sort(stones,stones+N);
  std::sort(ts,ts+N);
  std::vector<std::pair<int,int> > tasks;//(id,amount)
  for(int i=0;i<N;i++){
    if(ts[i]>stones[i].s){
      //need to move right
      tasks.emplace_back(stones[i].id,ts[i]-stones[i].s);
    }else{
      //need to move left
      int amt=stones[i].s-ts[i];
      while(amt>0){
	if(tasks.empty()){
	  fail();
	}
	int use=std::min(amt,tasks.back().second);
	ans.push_back({tasks.back().first,stones[i].id,use});
	amt-=use;
	tasks.back().second-=use;
	if(tasks.back().second==0){
	  tasks.pop_back();
	}
      }
    }
    assert(tasks.empty()||tasks.back().second!=0);
  }
  if(tasks.size()){
    fail();
  }
  printf("YES\n");
  printf("%d\n",(int)ans.size());
  for(auto it:ans){
    printf("%d %d %d\n",it[0]+1,it[1]+1,it[2]);
  }
  return 0;
}