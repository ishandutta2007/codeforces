#include <cstdio>
#include <map>

int as[5000];

bool set[5001];

int cnt[5001];

int main(){
  int N;
  scanf("%d",&N);
  std::map<int,int> cps;
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    for(int k=10000;k>0;k--){
      if(A%(k*k)==0){
	A/=(k*k);
      }
    }
    as[i]=A;
    if(A){
      cps[A];
    }
  }
  int last=1;
  for(auto& x:cps){
    x.second=last++;
  }
  for(int i=0;i<N;i++){
    if(as[i]){
      as[i]=cps[as[i]];
    }
  }
  set[0]=true;
  for(int i=0;i<N;i++){
    std::fill(set+1,set+N+1,false);
    int distinct=0;
    for(int j=i;j<N;j++){
      if(!set[as[j]]){
	set[as[j]]=true;
	distinct++;
      }
      cnt[distinct]++;
    }
  }
  printf("%d",cnt[0]+cnt[1]);
  for(int k=2;k<=N;k++){
    printf(" %d",cnt[k]);
  }
  printf("\n");
  return 0;
}