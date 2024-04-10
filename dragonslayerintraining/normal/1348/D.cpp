#include <cstdio>
#include <algorithm>
#include <vector>

void solve(){
  int N;
  scanf("%d",&N);
  std::vector<int> mass;
  for(int k=0;N;k++){
    int m=std::min(N,1<<k);
    mass.push_back(m);
    N-=m;
  }
  std::sort(mass.begin(),mass.end());
  printf("%d\n",(int)mass.size()-1);
  for(int i=0;i+1<mass.size();i++){
    printf("%d ",mass[i+1]-mass[i]);
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