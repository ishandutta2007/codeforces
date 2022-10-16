#include <cstdio>
#include <stdint.h>
#include <vector>
#include <algorithm>

std::vector<std::pair<int64_t,int64_t>> arrive[100000],depart[100000];

int64_t aprefix[1000001],dprefix[1000001];

int main(){
  int64_t N,M,K;
  scanf("%I64d %I64d %I64d",&N,&M,&K);
  for(int64_t i=0;i<M;i++){
    int64_t D,F,T,C;
    scanf("%I64d %I64d %I64d %I64d",&D,&F,&T,&C);
    if(T==0){
      arrive[F-1].emplace_back(D-1,C);
    }else{
      depart[T-1].emplace_back(D-1,C);
    }
  }
  
  for(int64_t j=0;j<N;j++){
    {
      std::sort(arrive[j].begin(),arrive[j].end());
      int64_t prev=1e12;
      for(int64_t i=0;i<arrive[j].size();i++){
	if(arrive[j][i].second<prev){
	  aprefix[arrive[j][i].first]-=(prev-arrive[j][i].second);
	  prev=arrive[j][i].second;
	}
      }
    }
    {
      std::sort(depart[j].begin(),depart[j].end());
      std::reverse(depart[j].begin(),depart[j].end());
      int64_t prev=1e12;
      for(int64_t i=0;i<depart[j].size();i++){
	if(depart[j][i].second<prev){
	  dprefix[depart[j][i].first]-=(prev-depart[j][i].second);
	  prev=depart[j][i].second;
	}
      }
    }
  }
  int64_t asum=N*1e12;
  for(int64_t j=0;j<=1000000;j++){
    asum+=aprefix[j];
    aprefix[j]=asum;
  }
  int64_t dsum=N*1e12;
  for(int64_t j=1000000;j>=0;j--){
    dsum+=dprefix[j];
    dprefix[j]=dsum;
  }
  int64_t best=1e12;
  for(int64_t i=K+1;i<=1000000;i++){
    best=std::min(best,aprefix[i-K-1]+dprefix[i]);
  }
  if(best<1e12){
    printf("%I64d\n",best);
  }else{
    printf("-1\n");
  }
  return 0;
}