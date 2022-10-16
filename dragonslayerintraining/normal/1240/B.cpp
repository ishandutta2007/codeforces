#include <cstdio>
#include <map>
#include <vector>

void solve(){
  std::map<int,std::vector<int> > where;
  int N;
  scanf("%d",&N);
  for(int i=1;i<=N;i++){
    int A;
    scanf("%d",&A);
    where[A].push_back(i);
  }
  int run=0;
  int best=0;
  int last=0;
  for(auto it:where){
    int L=it.second.front(),R=it.second.back();
    if(L>last){
      run++;
    }else{
      run=1;
    }
    best=std::max(best,run);
    last=R;
  }
  printf("%d\n",(int)where.size()-best);
}
     
int main(){
  int Q;
  scanf("%d",&Q);
  while(Q--){
    solve();
  }
}