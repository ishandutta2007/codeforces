#include <iostream>
#include <map>

char inv[26];

int main(){
  int N,K;
  std::string S;
  std::cin>>N>>K>>S;
  std::map<char,int> cps;
  for(int i=0;i<N;i++){
    cps[S[i]];
  }
  int last=0;
  for(auto& pair:cps){
    inv[last]=pair.first;
    pair.second=last++;
  }
  if(K>N){
    std::cout<<S;
    for(;N<K;N++){
      std::cout<<inv[0];
    }
    std::cout<<std::endl;
    return 0;
  }
  for(int i=0;i<N;i++){
    S[i]=cps[S[i]];
  }
  S.resize(K);
  int i=K-1;
  while(++S[i]==last){
    S[i--]=0;
  }
  for(int i=0;i<N;i++){
    S[i]=inv[S[i]];
  }
  std::cout<<S<<std::endl;
  return 0;
}