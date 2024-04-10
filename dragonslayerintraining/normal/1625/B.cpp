#include <cstdio>
#include <map>
#include <vector>

void solve(){
  int N;
  scanf("%d",&N);
  std::map<int,std::vector<int> > at;
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    at[A].push_back(i);
  }
  int best=-1;
  for(auto it:at){
    auto& vec=it.second;
    for(int i=0;i+1<vec.size();i++){
      int tmp=N-(vec[i+1]-vec[i]);
      if(best==-1||tmp>best){
	best=tmp;
      }
    }
  }
  printf("%d\n",best);
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}