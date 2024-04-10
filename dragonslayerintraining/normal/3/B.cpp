#include <iostream>
#include <algorithm>
#include <vector>

std::vector<std::pair<int,int> > kayaks,catamarans;

int main(){
  int N,V;
  std::cin>>N>>V;
  for(int i=0;i<N;i++){
    int vol,cap;
    std::cin>>vol>>cap;
    if(vol==1){
      kayaks.push_back(std::make_pair(cap,i+1));
    }else{
      catamarans.push_back(std::make_pair(cap,i+1));
    }
  }
  kayaks.push_back(std::make_pair(0,-1));
  kayaks.push_back(std::make_pair(0,-1));
  catamarans.push_back(std::make_pair(0,-1));
  std::sort(kayaks.begin(),kayaks.end());
  std::reverse(kayaks.begin(),kayaks.end());
  std::sort(catamarans.begin(),catamarans.end());
  std::reverse(catamarans.begin(),catamarans.end());
  int k_i=0,c_i=0;
  int total_cap=0;
  while(V>0){
    if((kayaks[k_i].first==0)&&(catamarans[c_i].first==0)){
      break;
    }
    if((kayaks[k_i].first*2<catamarans[c_i].first)&&(V>=2)){
      V-=2;
      total_cap+=catamarans[c_i++].first;
    }else if(kayaks[k_i].first>0){
      V-=1;
      total_cap+=kayaks[k_i++].first;
    }else{
      break;
    }
  }
  if((k_i>1)&&(kayaks[k_i-1].first+kayaks[k_i-2].first<catamarans[c_i].first)){
    total_cap-=kayaks[--k_i].first;
    total_cap-=kayaks[--k_i].first;
    total_cap+=catamarans[c_i++].first;
  }
  if((k_i>0)&&(V>0)&&(kayaks[k_i-1].first<catamarans[c_i].first)){
    total_cap-=kayaks[--k_i].first;
    total_cap+=catamarans[c_i++].first;
  }
  if((c_i>0)&&(kayaks[k_i].first+kayaks[k_i+1].first>catamarans[c_i-1].first)){
    total_cap+=kayaks[k_i++].first;
    total_cap+=kayaks[k_i++].first;
    total_cap-=catamarans[--c_i].first;
  }
  std::cout<<total_cap<<std::endl;
  for(int i=0;i<k_i;i++){
    std::cout<<kayaks[i].second<<std::endl;
  }
  for(int i=0;i<c_i;i++){
    std::cout<<catamarans[i].second<<std::endl;
  }
  return 0;
}