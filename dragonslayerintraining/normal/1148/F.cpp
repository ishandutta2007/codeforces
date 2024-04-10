#include <cstdio>
#include <stdint.h>
#include <map>

std::map<long long,long long> freq;

int main(){
  int N;
  scanf("%d",&N);
  long long sum=0;
  while(N--){
    long long val;
    long long mask;
    scanf("%lld %lld",&val,&mask);
    freq[mask]+=val;
    sum+=val;
  }
  //wlog, sum>0
  if(sum<0){
    for(auto& it:freq){
      it.second*=-1;
    }
  }
  long long mask=0;
  long long expect=0;//expected sum if remaining bits chosen randomly
  for(int k=61;k>=0;k--){
    //expected sum if next bit fixed as 0
    long long sub=0;
    for(auto it:freq){
      if((it.first&((1LL<<k)-1))==0){
	sub+=(__builtin_popcountll(mask&it.first)%2?-1:1)*it.second;
      }
    }
    //pick bit with lower expected sum
    //break ties with 0 to use sum>0 condition
    if(sub>expect-sub){
      mask|=(1LL<<k);
      expect-=sub;
    }else{
      expect=sub;
    }
  }
  printf("%lld\n",mask);
}