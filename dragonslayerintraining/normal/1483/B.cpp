#include <cstdio>
#include <vector>
#include <set>

int as[100005];

int gcd(int a,int b){
  return b?gcd(b,a%b):a;
}

void solve(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  std::vector<int> prev(N),next(N);
  for(int i=0;i<N;i++){
    prev[i]=(i+N-1)%N;
    next[i]=(i+1)%N;
  }
  std::set<int> cand;
  auto is_cand=[&](int i){return gcd(as[i],as[prev[i]])==1;};
  for(int i=0;i<N;i++){
    if(is_cand(i)){
      cand.insert(i);
    }
  }
  std::vector<int> del;
  int i=0;
  while(!cand.empty()){
    //don't remember
    //now remember i
    auto it=cand.upper_bound(i);
    if(it==cand.end()){
      i=*cand.begin();
    }else{
      i=*it;
    }
    del.push_back(i);
    if(i==prev[i]) break;
    prev[next[i]]=prev[i];
    next[prev[i]]=next[i];
    cand.erase(i);
    i=next[i];
    cand.insert(i);
    if(!is_cand(i)){
      cand.erase(i);
    }
  }
  printf("%d",(int)del.size());
  for(int i:del){
    printf(" %d",i+1);
  }
  printf("\n");
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}