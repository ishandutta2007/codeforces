#include <cstdio>
#include <vector>
#include <algorithm>
#include <cassert>

unsigned long long count_perms(std::vector<int> vs){
  unsigned long long ans=1;
  int run=1;
  for(int i=0;i<vs.size();i++){
    int slots=vs.size()-vs[i]-(vs.size()-i-1);
    ans*=slots;
    assert(ans%run==0);
    ans/=run;
    if(i==vs.size()-1) break;
    if(vs[i]==vs[i+1]){
      run++;
    }else{
      run=1;
    }
  }
  return ans;
}

void solve(){
  long long K;
  scanf("%lld",&K);
  //printf("fingerprint of %lld:",K);
  std::vector<int> vec;
  for(int i=2;K;i++){
    vec.push_back(K%i);
    K/=i;
  }
  vec.insert(vec.begin(),0);
  std::sort(vec.begin(),vec.end());
  /*
  for(int x:vec){
    printf(" %d",x);
  }printf("\n");
  */
  unsigned long long ans=count_perms(vec);
  vec.erase(vec.begin());
  //printf("ans'=%lld\n",ans);
  ans-=count_perms(vec);
  printf("%lld\n",ans-1);
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}