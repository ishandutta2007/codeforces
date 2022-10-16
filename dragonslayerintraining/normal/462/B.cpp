#include <iostream>
#include <algorithm>
#include <vector>
#include <stdint.h>

std::vector<int64_t> vs;
int64_t cnt[256];

int main(){
  int64_t N,K;
  std::string str;
  std::cin>>N>>K;
  std::cin>>str;
  for(char c:str){
    cnt[c]++;
  }
  for(char c:str){
    vs.push_back(cnt[c]);
  }
  std::sort(cnt,cnt+256);
  std::reverse(cnt,cnt+256);
  int64_t best=0;
  for(int i=0;i<256;i++){
    int64_t use=std::min(K,cnt[i]);
    best+=use*use;
    K-=use;
  }
  std::cout<<best<<std::endl;
  return 0;
}