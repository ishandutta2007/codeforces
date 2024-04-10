#include <cstdio>
#include <set>
#include <algorithm>

int xs[100005];

void solve(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&xs[i]);
  }
  std::sort(xs,xs+N);
  std::set<int> set;
  for(int i=0;i<N;i++){
    if(set.count(xs[i])){
      set.insert(xs[i]+1);
    }else{
      set.insert(xs[i]);
    }
  }
  printf("%d\n",(int)set.size());
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}