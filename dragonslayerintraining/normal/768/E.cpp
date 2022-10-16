#include <iostream>
#include <set>
#include <map>

std::map<long long,long long> memo[61];

long long grundy(long long num,long long forbidden){
  forbidden&=((1LL<<num)-1);
  if(memo[num].count(forbidden)){
    return memo[num][forbidden];
  }
  std::set<long long> ord;
  for(long long i=1;i<=num;i++){
    //remove i stones if not done yer
    if((forbidden&(1LL<<(i-1)))==0){
      ord.insert(grundy(num-i,forbidden|(1LL<<(i-1))));
    }
  }
  for(long long i=0;;i++){
    if(!ord.count(i)){
      memo[num][forbidden]=i;
      return i;
    }
  }
}

long long a[61];

int main(){
  long long N;
  std::cin>>N;
  for(long long i=0;i<N;i++){
    long long S;
    std::cin>>S;
    a[S]^=1;
  }
  long long ac=0;
  for(long long i=0;i<=60;i++){
    if(a[i]){
      ac^=grundy(i,0);
    }
    //std::cout<<i<<"\t"<<grundy(i,0)<<std::endl;
  }
  std::cout<<(ac?"NO":"YES")<<std::endl;
  return 0;
}