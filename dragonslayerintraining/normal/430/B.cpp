#include <iostream>
#include <vector>

std::vector<int> color;

int main(){
  int N,K,X;
  std::cin>>N>>K>>X;
  for(int i=0;i<N;i++){
    int C;
    std::cin>>C;
    color.push_back(C);
  }
  int best=0;
  for(int i=1;i<N;i++){
    int destroy=-1;
    std::vector<int> copy=color;
    copy.insert(copy.begin()+i,X);
    std::vector<std::pair<int,int> > tmp;
    for(int i=0;i<copy.size();){
      int run=tmp.size()?tmp.back().second:0;
      if((tmp.size()>0)&&(copy[i]==tmp.back().first)){
	run++;
      }else{
	run=1;
      }
      tmp.emplace_back(copy[i],run);
      if(run==3){
	int kill=copy[i];
	while(tmp.back().first==kill){
	  tmp.pop_back();
	  destroy++;
	}
	i++;
	while(i<copy.size()&&copy[i]==kill){
	  destroy++;
	  i++;
	}
      }else{
	i++;
      }
    }
    best=std::max(best,destroy);
  }
  std::cout<<best<<std::endl;
  return 0;
}