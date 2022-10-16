#include <iostream>
#include <algorithm>
#include <set>

int N,K;
int s[100002];

int opt(int S){
  int cnt=0;
  for(std::multiset<int> vals(s,s+N);vals.size()>0;cnt++){
    int max=*vals.rbegin();
    vals.erase(vals.find(max));
    std::multiset<int>::iterator other=vals.upper_bound(S-max);
    if(other==vals.begin()){
      continue;
    }
    --other;
    vals.erase(other);
  }
  return cnt;
}

int main(){
  std::cin>>N>>K;
  for(int i=0;i<=N-1;i++){
    std::cin>>s[i];
  }
  int low=s[N-1]-1,high=2000000;
  while(high-low>1){
    int mid=(low+high)/2;
    if(opt(mid)>K){
      low=mid;
    }else{
      high=mid;
    }
  }
  std::cout<<high<<std::endl;
  return 0;
}