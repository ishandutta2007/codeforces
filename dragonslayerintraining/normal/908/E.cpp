#include <iostream>
#include <stdint.h>
#include <map>

const int64_t MOD=1e9+7;

int64_t M,N;

int64_t occur[1000];

std::map<int64_t,int64_t> size;

int64_t combo[1001][1001];
int64_t parts[1001];

int main(){
  for(int64_t i=0;i<=1000;i++){
    combo[i][0]=1;
    combo[0][i]=1;
  }
  for(int64_t i=1;i<=1000;i++){
    for(int64_t j=1;j<=1000;j++){
      combo[i][j]=(combo[i][j-1]+combo[i-1][j])%MOD;
    }
  }
  parts[0]=1;
  for(int64_t i=0;i<=1000;i++){
    for(int64_t k=0;k<i;k++){
      parts[i]=(parts[i]+combo[i-1-k][k]*parts[k])%MOD;
    }
  }
  std::cin>>M>>N;
  for(int64_t i=0;i<N;i++){
    std::string str;
    std::cin>>str;
    for(int64_t j=0;j<str.length();j++){
      occur[j]|=((int64_t(str[j]-'0'))<<i);
    }
  }
  for(int64_t i=0;i<M;i++){
    size[occur[i]]++;
  }
  int64_t cnt=1;
  for(std::pair<int64_t,int64_t> pair:size){
    int64_t sz=pair.second;
    cnt=cnt*parts[sz]%MOD;
  }
  std::cout<<cnt<<std::endl;
  return 0;
}