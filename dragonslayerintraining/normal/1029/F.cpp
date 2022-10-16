#include <cstdio>
#include <set>
#include <vector>
#include <stdint.h>

std::vector<int64_t> big;
std::set<int64_t> unmarked;

void factorize(int64_t N,std::vector<int64_t>& factors){
  for(int64_t i=1;i*i<=N;i++){
    if(N%i==0){
      factors.push_back(i);
    }
  }
  for(int64_t i=(int)factors.size()-1-(factors.back()*factors.back()==N);i>=0;i--){
    factors.push_back(N/factors[i]);
  }
}

void check(int64_t A){
  std::vector<int64_t> small;
  factorize(A,small);
  for(int64_t i=0;i*2<small.size();i++){
    auto it1=std::lower_bound(big.begin(),big.end(),small[i]);
    auto it2=std::lower_bound(big.begin(),big.end(),small[small.size()-1-i]);
    if(it1==big.end()||it2==big.end()) continue;
    int64_t L=it1-big.begin();
    int64_t R=big.end()-it2;
    for(auto it=unmarked.lower_bound(L);it!=unmarked.end()&&*it<R;it=unmarked.lower_bound(L)){
      unmarked.erase(it);
    }
  }
}

int main(){
  int64_t A,B;
  scanf("%I64d %I64d",&A,&B);
  factorize(A+B,big);
  for(int64_t i=0;i*2<big.size();i++){
    unmarked.insert(i);
  }
  check(A);
  check(B);
  int64_t P=1e15;
  for(int64_t i=0;i*2<big.size();i++){
    if(!unmarked.count(i)){
      P=std::min(P,2*(big[i]+big[big.size()-1-i]));
    }
  }
  printf("%I64d\n",P);
  return 0;
}