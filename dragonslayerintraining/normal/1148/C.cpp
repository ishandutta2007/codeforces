#include <cstdio>
#include <vector>
#include <algorithm>

int ps[300005];
int where[300005];
int N;

std::vector<std::pair<int,int> > ans;

void exchange(int i,int j){
  if(i==j) return;
  ans.emplace_back(i,j);
  std::swap(ps[i],ps[j]);
  std::swap(where[ps[i]],where[ps[j]]);
}

int main(){
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&ps[i]);
    ps[i]--;
    where[ps[i]]=i;
  }
  for(int i=1;i<N-1;i++){
    int first=(where[i]<N/2)?(N-1):0;
    int second=(i<N/2)?(N-1):0;
    exchange(where[i],first);
    exchange(first,second);
    exchange(second,i);
  }
  if(ps[0]!=0){
    exchange(0,N-1);
  }
  printf("%d\n",(int)ans.size());
  for(auto it:ans){
    printf("%d %d\n",it.first+1,it.second+1);
  }
  return 0;
}