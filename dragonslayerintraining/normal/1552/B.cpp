#include <cstdio>
#include <cassert>

int r[50005][5];

//i beats j
bool beat(int i,int j){
  assert(i!=j);
  int cnt=0;
  for(int k=0;k<5;k++){
    if(r[i][k]<r[j][k]){
      cnt++;
    }
  }
  return cnt>=3;
}

void solve(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    for(int k=0;k<5;k++){
      scanf("%d",&r[i][k]);
    }
  }
  int cand=0;
  for(int i=1;i<N;i++){
    if(beat(i,cand)){
      cand=i;
    }
  }
  for(int i=0;i<N;i++){
    if(cand==i) continue;
    if(beat(i,cand)){
      printf("-1\n");
      return;
    }
  }
  printf("%d\n",cand+1);
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}