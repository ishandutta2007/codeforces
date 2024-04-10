#include <cstdio>
#include <vector>
#include <cstdlib>

int query(const std::vector<int>& as,const std::vector<int>& bs){
  if(as.empty()||bs.empty()) return 0;
  printf("%d %d",(int)as.size(),(int)bs.size());
  for(int a:as) printf(" %d",a+1);
  for(int b:bs) printf(" %d",b+1);
  printf("\n");
  fflush(stdout);
  int ans;
  scanf("%d",&ans);
  if(ans==-1) exit(0);
  return ans;
}


void solve(){
  int N;
  scanf("%d",&N);
  int best=0;
  for(int k=0;k<9;k++){
    std::vector<int> as,bs;
    for(int i=0;i<N;i++){
      if(i&(1<<k)){
	as.push_back(i);
      }else{
	bs.push_back(i);
      }
    }
    best=std::max(best,query(as,bs));
  }
  printf("-1 %d\n",best);
  fflush(stdout);
}

int main(){
  int T;
  scanf("%d",&T);
  while(T-->0){
    solve();
  }
  return 0;
}