#include <cstdio>
#include <algorithm>
#include <set>

const int INF=1e9+7;

bool has[5000006];
int far[5000006];
int flag[5000006];

void solve(){
  int N,M;
  scanf("%d %d",&N,&M);
  std::fill(has,has+M+1,false);
  std::fill(far,far+M+1,M+1);
  std::fill(flag,flag+M+2,0);
  std::set<std::pair<int,int> > multiset;
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    has[A]=true;
  }
  for(int i=1;i<=M;i++){
    if(has[i]){
      flag[M+1]++;
    }
  }
  int r=M+1;
  int best=INF;
  for(int i=M;i>=1;i--){
    if(has[i]){
      flag[far[i]]--;
    }
    far[i]=i;
    if(has[i]){
      flag[far[i]]++;
    }
    for(int j=i+i;j<=M;j+=i){
      if(far[j]<=far[j/i]) continue;
      if(has[j]){
	flag[far[j]]--;
      }
      far[j]=far[j/i];
      if(has[j]){
	flag[far[j]]++;
      }
    }
    while(!flag[r]) r--;
    if(r<=M){
      best=std::min(best,r-i);
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