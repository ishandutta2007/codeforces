#include <cstdio>
#include <map>
#include <vector>
#include <stdint.h>
#include <cassert>
#include <algorithm>

const int64_t BILLION=1000000000LL;
const int64_t MAXIN=BILLION*BILLION;
int64_t N,L;

int64_t query(int i,int64_t x){
  if(x==0) return 0;
  if(x==MAXIN) return L;
  printf("? %d %I64d\n",i+1,x);
  fflush(stdout);
  int64_t res;
  scanf("%I64d",&res);
  return res;
}

std::pair<int64_t,int64_t> ans[1005];

int64_t locate(int i,int64_t low,int64_t high,int64_t thres){
  while(high-low>1){
    int64_t mid=(low+high)/2;
    if(query(i,mid)>=thres){
      high=mid;
    }else{
      low=mid;
    }
  }
  return high;
}

void solve(std::vector<int> is,int64_t ll,int64_t rr,int64_t base){
  if(is.size()==1){
    ans[is[0]]={ll,rr};
    return;
  }
  int64_t crit=L/N*(is.size()/2)+base;
  int64_t k=is.size()/2;
  std::vector<int> sub(is);
  std::vector<int> left,right;
  int64_t pivot_value;
  while(sub.size()){
    int pivot_index=sub[rand()%sub.size()];
    pivot_value=locate(pivot_index,ll,rr,crit);
    std::vector<int> small,medium,big;
    for(int i:sub){
      if(query(i,pivot_value)<crit){
	big.push_back(i);
      }else if(query(i,pivot_value-1)<crit){
	medium.push_back(i);
      }else{
	small.push_back(i);
      }
    }
    if(k>=small.size()+medium.size()){
      k-=small.size()+medium.size();
      left.insert(left.end(),small.begin(),small.end());
      left.insert(left.end(),medium.begin(),medium.end());
      sub=big;
    }else if(k>=small.size()){
      k-=small.size();
      left.insert(left.end(),small.begin(),small.end());
      left.insert(left.end(),medium.begin(),medium.begin()+k);
      right.insert(right.end(),big.begin(),big.end());
      right.insert(right.end(),medium.begin()+k,medium.end());
      break;
    }else{
      right.insert(right.end(),big.begin(),big.end());
      right.insert(right.end(),medium.begin(),medium.end());
      sub=small;
    }
  }
  assert(left.size()<=is.size()/2);
  assert(right.size()<=is.size()-is.size()/2);
  solve(left,ll,pivot_value,base);
  solve(right,pivot_value,rr,crit);
}

int main(){
  scanf("%I64d %I64d",&N,&L);
  std::vector<int> is;
  for(int i=0;i<N;i++){
    is.push_back(i);
  }
  solve(is,0,MAXIN,0);
  printf("!\n");
  for(int i=0;i<N;i++){
    printf("%I64d %I64d\n",ans[i].first,ans[i].second);
  }
  return 0;
}