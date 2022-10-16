#include <iostream>
#include <stdint.h>

int64_t cnt[40000];

int main(){
  int64_t A;
  std::string str;
  std::cin>>A>>str;
  for(int64_t i=0;i<str.length();i++){
    int64_t sum=0;
    for(int64_t j=i;j<str.length();j++){
      sum+=str[j]-'0';
      cnt[sum]++;
    }
  }
  if(A==0){
    std::cout<<2*cnt[0]*(str.length()*(str.length()+1)/2-cnt[0])+cnt[0]*cnt[0]<<std::endl;
    return 0;
  }
  int64_t ans=0;
  for(int64_t i=1;i*i<=A;i++){
    if(A%i) continue;
    if(i>=40000||A/i>=40000) continue;
    ans+=cnt[i]*cnt[A/i];
    if(i*i<A){
      ans+=cnt[i]*cnt[A/i];
    }
  }
  std::cout<<ans<<std::endl;
  return 0;
}