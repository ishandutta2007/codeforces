#include <iostream>
#include <vector>
#include <algorithm>

int overall[501];

int main(){
  int N,M,K;
  std::cin>>N>>M>>K;
  std::fill(overall,overall+501,0);
  while(N-->0){
    int day[501];
    std::fill(day,day+501,1e9);
    std::string times;
    std::cin>>times;
    std::vector<int> classes;
    for(int i=0;i<times.size();i++){
      if(times[i]=='1'){
	classes.push_back(i);
      }
    }
    std::fill(day+classes.size(),day+501,0);
    for(int pre=0;pre<classes.size();pre++){
      for(int post=0;pre+post<classes.size();post++){
	day[pre+post]=std::min(day[pre+post],
			       classes[classes.size()-post-1]-classes[pre]+1);
      }
    }
    int tmp[501];
    std::fill(tmp,tmp+501,1e9);
    for(int a=0;a<=K;a++){
      for(int b=0;a+b<=K;b++){
	tmp[a+b]=std::min(tmp[a+b],day[a]+overall[b]);
      }
    }
    for(int i=0;i<=K;i++){
      overall[i]=tmp[i];
    }
  }
  std::cout<<overall[K]<<std::endl;
  
  return 0;
}