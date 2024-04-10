#include <iostream>
#include <vector>

int xs[100000];

int cnt[3];
int change1[3];
int change2[3];

int main(){
  int N;
  std::cin>>N;
  int min=1e9,max=-1e9;
  for(int i=0;i<N;i++){
    std::cin>>xs[i];
    min=std::min(min,xs[i]);
    max=std::max(max,xs[i]);
  }
  if(max-min<2){
    std::cout<<N<<std::endl;
    for(int i=0;i<N;i++){
      if(i>0) std::cout<<" ";
      std::cout<<xs[i];
    }
    std::cout<<std::endl;
    return 0;
  }
  for(int i=0;i<N;i++){
    cnt[xs[i]-min]++;
  }
  for(int i=0;i<3;i++){
    change1[i]=change2[i]=cnt[i];
  }
  while(change1[1]>1){
    change1[0]++;
    change1[1]-=2;
    change1[2]++;
  }
  int cost1=std::min(cnt[0],change1[0])+
    std::min(cnt[1],change1[1])+
    std::min(cnt[2],change1[2]);
  while(change2[0]>0&&change2[2]>0){
    change2[0]--;
    change2[1]+=2;
    change2[2]--;
  }
  int cost2=std::min(cnt[0],change2[0])+
    std::min(cnt[1],change2[1])+
    std::min(cnt[2],change2[2]);
  std::vector<int> vs;
  if(cost1<cost2){
    for(int x=0;x<3;x++){
      for(int i=0;i<change1[x];i++){
	vs.push_back(min+x);
      }
    }
  }else{
    for(int x=0;x<3;x++){
      for(int i=0;i<change2[x];i++){
	vs.push_back(min+x);
      }
    }
  }
  std::cout<<std::min(cost1,cost2)<<std::endl;
  for(int i=0;i<vs.size();i++){
    if(i>0) std::cout<<" ";
    std::cout<<vs[i];
  }
  std::cout<<std::endl;
  return 0;
}