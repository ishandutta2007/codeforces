#include <cstdio>
#include <map>
#include <vector>

std::map<long long,int> factors;

int main(){
  long long N;
  scanf("%lld",&N);
  long long x=N;
  for(int i=2;1LL*i*i<=N;i++){
    while(x%i==0){
      factors[i]++;
      x/=i;
    }
  }
  if(x>1){
    factors[x]++;
  }
  if(factors.size()!=1){
    printf("%d\n",1);
  }else{
    printf("%lld\n",factors.begin()->first);
  }
}