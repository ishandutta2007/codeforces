#include <cstdio>
#include <cassert>
#include <stdint.h>
#include <map>
#include <vector>

const int64_t MOD=998244353;

std::map<int64_t,int64_t> factors;
std::vector<int64_t> semi;

int64_t gcd(int64_t a,int64_t b){
  return b?gcd(b,a%b):a;
}

bool is_square(int64_t a,int64_t& root){
  int64_t low=0,high=2e9;
  while(high-low>1){
    int64_t mid=(low+high)/2;
    if(a>mid*mid){
      low=mid;
    }else if(a<mid*mid){
      high=mid;
    }else{
      root=mid;
      return true;
    }
  }
  return false;
}
bool is_cube(int64_t a,int64_t& root){
  int64_t low=0,high=2e6;
  while(high-low>1){
    int64_t mid=(low+high)/2;
    if(a>mid*mid*mid){
      low=mid;
    }else if(a<mid*mid*mid){
      high=mid;
    }else{
      root=mid;
      return true;
    }
  }
  return false;
}

int main(){
  int64_t N;
  scanf("%I64d",&N);
  for(int64_t i=0;i<N;i++){
    int64_t A;
    scanf("%I64d",&A);
    int64_t B,C;
    if(is_square(A,B)){
      if(is_square(B,C)){
	factors[C]+=4;
	//printf("Add %I64d^4\n",C);
      }else{
	factors[B]+=2;
	//printf("Add %I64d^2\n",B);
      }
    }else if(is_cube(A,B)){
      factors[B]+=3;
    }else{
      semi.push_back(A);
    }
  }
  for(int64_t i=0;i<semi.size();i++){
    for(int64_t j=0;j<semi.size();j++){
      if(semi[i]==semi[j]) continue;
      int64_t g=gcd(semi[i],semi[j]);
      if(g!=1){
	factors[semi[i]/g];
	factors[semi[j]/g];
	factors[g];
      }
    }
  }
  std::vector<int64_t> primes;
  for(auto it:factors){
    primes.push_back(it.first);
    //printf("PRIME %I64d\n",it.first);
  }
  for(int pi=0;pi<primes.size();pi++){
    int64_t p=primes[pi];
    for(int64_t i=0;i<semi.size();i++){
      if(semi[i]%p==0){
	if(!factors.count(semi[i]/p)){
	  primes.push_back(semi[i]/p);
	}
	factors[p]++;
	factors[semi[i]/p]++;
	semi[i]=1;
      }
    }
  }
  std::map<int64_t,int64_t> pairs;
  for(int64_t i=0;i<semi.size();i++){
    if(semi[i]!=1){
      pairs[semi[i]]++;
    }
  }
  int64_t ac=1;
  for(auto it:factors){
    ac=ac*(it.second+1)%MOD;
    //printf("%I64d^%I64d \n",it.first,it.second);
  }
  for(auto it:pairs){
    ac=ac*(it.second+1)%MOD*(it.second+1)%MOD;
    //printf("(%I64d)^%I64d \n",it.first,it.second);
  }
  printf("%I64d\n",ac);
  fflush(stdout);
  return 0;
}