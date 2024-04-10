#include <cstdio>
#include <vector>
#include <algorithm>

void solve(){
  int N,M;
  scanf("%d %d",&N,&M);
  std::vector<std::vector<int>> day(M);
  std::vector<int> freq(N);
  for(int i=0;i<M;i++){
    int K;
    scanf("%d",&K);
    for(int k=0;k<K;k++){
      int F;
      scanf("%d",&F);
      day[i].push_back(F-1);
    }
    if(day[i].size()==1){
      freq[day[i][0]]++;
    }
  }
  std::vector<int> as(M);
  for(int i=0;i<M;i++){
    as[i]=day[i][0];
  }
  std::vector<int> ord;
  for(int i=0;i<M;i++){
    if(day[i].size()==1){
      ord.push_back(i);
    }
  }
  std::sort(ord.begin(),ord.end(),[&](int a,int b){return day[a][0]<day[b][0];});
  for(int i=0;i<M;i++){
    if(day[i].size()!=1){
      ord.push_back(i);
    }
  }
  for(int i=0;i<M/2;i++){
    int a=ord[i];
    int b=ord[i+(M+1)/2];
    if(day[a][0]==day[b][0]){
      if(day[a].size()>1){
	as[a]=day[a][1];
      }else if(day[b].size()>1){
	as[b]=day[b][1];
      }else{
	printf("NO\n");
	return;
      }
    }
  }
  printf("YES\n");
  for(int i=0;i<M;i++){
    if(i) printf(" ");
    printf("%d",as[i]+1);
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