#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> good;

int best=1e9;

void check(int l,int m,int r){
  best=std::min(best,std::max(good[r]-good[m],good[m]-good[l]));
}


int main(){
  int N,K;
  std::string str;
  std::cin>>N>>K;
  std::cin>>str;
  for(int i=0;i<str.length();i++){
    if(str[i]=='0'){
      good.push_back(i);
    }
  }
  int m=0;
  for(int i=0;i+K<good.size();i++){
    while(good[i+K]-good[m]>good[m]-good[i]){
      check(i,m,i+K);
      m++;
    }
    check(i,m,i+K);
  }
  std::cout<<best<<std::endl;
  return 0;
}