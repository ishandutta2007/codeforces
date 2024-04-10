#include <iostream>
#include <algorithm>
#include <vector>
#include <stdint.h>

int ps[100000];
int size[100000];
std::vector<int> cmpts;

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>ps[i];
    ps[i]--;
  }
  for(int i=0;i<N;i++){
    if(size[i]==0){
      int cnt=1;
      for(int j=ps[i];j!=i;j=ps[j]){
	cnt++;
      }
      for(int j=ps[i];j!=i;j=ps[j]){
	size[j]=cnt;
      }
      size[i]=cnt;
      cmpts.push_back(size[i]);
    }
  }
  std::sort(cmpts.begin(),cmpts.end());
  if(cmpts.size()>1){
    int x=cmpts.back();
    cmpts.pop_back();
    int y=cmpts.back();
    cmpts.pop_back();
    cmpts.push_back(x+y);
  }
  int64_t conv=0;
  for(int cmpt:cmpts){
    conv+=int64_t(cmpt)*cmpt;
  }
  std::cout<<conv<<std::endl;
  return 0;
}