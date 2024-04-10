#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

std::map<std::string,std::vector<int> > pal;
std::map<std::string,std::pair<std::vector<int>,std::vector<int> > > notpal;

int dp[2];

int main(){
  int K,N;
  std::cin>>K>>N;
  for(int i=0;i<K;i++){
    std::string S;
    int A;
    std::cin>>S>>A;
    std::string T=S;
    std::reverse(T.begin(),T.end());
    if(S<T){
      notpal[S].first.push_back(A);
    }else if(S>T){
      notpal[T].second.push_back(A);
    }else{
      pal[S].push_back(A);
    }
  }
  for(auto& it:pal){
    auto& v=it.second;
    std::sort(v.begin(),v.end(),std::greater<int>());
    int sum=0;
    int parity[2]={0,0};
    for(int i=0;i<v.size();i++){
      sum+=v[i];
      parity[(i+1)%2]=std::max(parity[(i+1)%2],sum);
    }
    dp[1]=std::max(dp[1]+parity[0],dp[0]+parity[1]);
    dp[0]=dp[0]+parity[0];
  }
  int extra=0;
  for(auto& it:notpal){
    auto& v1=it.second.first;
    auto& v2=it.second.second;
    std::sort(v1.begin(),v1.end(),std::greater<int>());    
    std::sort(v2.begin(),v2.end(),std::greater<int>());
    for(int i=0;i<v1.size()&&i<v2.size();i++){
      if(v1[i]+v2[i]>0){
	extra+=v1[i]+v2[i];
      }else{
	break;
      }
    }
  }
  printf("%d\n",std::max(dp[0],dp[1])+extra);
}