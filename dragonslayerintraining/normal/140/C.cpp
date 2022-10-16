#include <iostream>
#include <map>
#include <algorithm>
#include <queue>

int N;

struct csnowman{
  int r[3];
  csnowman(int r1,int r2,int r3){
    r[0]=r1;
    r[1]=r2;
    r[2]=r3;
    std::sort(r,r+3);
  }
};

std::vector<struct csnowman> snowmen;

int main(){
  std::cin>>N;
  std::map<int,int> byradius;
  for(int i=0;i<N;i++){
    int R;
    std::cin>>R;
    byradius[R]++;
  }
  std::priority_queue<std::pair<int,int> > snowballs;
  for(std::map<int,int>::iterator it=byradius.begin();it!=byradius.end();it++){
    snowballs.push(std::make_pair(it->second,it->first));
  }
  while(snowballs.size()>=3){
    std::pair<int,int> b[3];
    for(int i=0;i<3;i++){
      b[i]=snowballs.top();
      snowballs.pop();
    }
    snowmen.push_back(csnowman(b[0].second,b[1].second,b[2].second));
    for(int i=0;i<3;i++){
      if(--b[i].first>0){
	snowballs.push(b[i]);
      }
    }
  }
  std::cout<<snowmen.size()<<std::endl;
  for(int i=0;i<snowmen.size();i++){
    for(int j=2;j>=0;j--){
      if(j<2){
	std::cout<<" ";
      }
      std::cout<<snowmen[i].r[j];
    }
    std::cout<<std::endl;
  }
  return 0;
}