#include <cstdio>
#include <set>

int xs[100005];

void solve(){
  int N;
  scanf("%d",&N);
  std::set<int> set;
  for(int i=0;i<N;i++){
    scanf("%d",&xs[i]);
  }
  for(int i=0;i<N;i++){
    for(int j=i+1;j<N;j++){
      set.insert(xs[j]-xs[i]);
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