#include <cstdio>
#include <vector>
#include <cassert>
#include <stdint.h>

const int CRIT=400;
const int MAX_BIG=100005/CRIT+1;

int64_t init_var[100005];
int64_t delta[100005];
int64_t init_ans[100005];

std::vector<int> sets[100005];
int big_id[100005];
int big_cnt=0;

int64_t impact[MAX_BIG][100005];
int64_t updated[MAX_BIG];
int64_t query[MAX_BIG];//current answer for big

int has[100005];

int main(){
  int N,M,Q;
  scanf("%d %d %d",&N,&M,&Q);
  for(int i=0;i<N;i++){
    scanf("%I64d",&init_var[i]);
  }
  for(int i=0;i<M;i++){
    int K;
    scanf("%d",&K);
    while(K--){
      int X;
      scanf("%d",&X);
      X--;
      sets[i].push_back(X);
      init_ans[i]+=init_var[X];
    }
  }
  std::fill(big_id,big_id+N,-1);
  for(int i=0;i<M;i++){
    if(sets[i].size()>CRIT){
      big_id[i]=big_cnt++;
      for(int x:sets[i]){
	has[x]++;
      }
      for(int j=0;j<M;j++){
	for(int x:sets[j]){
	  impact[big_id[i]][j]+=has[x];
	}
      }
      for(int x:sets[i]){
	has[x]--;
      }
    }
  }
  while(Q--){
    char T;
    scanf(" %c",&T);
    if(T=='?'){
      int K;
      scanf("%d",&K);
      K--;
      if(big_id[K]==-1){
	//small
	int64_t res=init_ans[K];
	for(int id=0;id<big_cnt;id++){
	  res+=impact[id][K]*updated[id];
	}
	for(int x:sets[K]){
	  res+=delta[x];
	}
	printf("%I64d\n",res);
      }else{
	//big
	printf("%I64d\n",init_ans[K]+query[big_id[K]]);
      }
    }else if(T=='+'){
      int K,X;
      scanf("%d %d",&K,&X);
      K--;
      for(int id=0;id<big_cnt;id++){
	query[id]+=impact[id][K]*X;
      }
      if(big_id[K]==-1){
	//small
	for(int x:sets[K]){
	  delta[x]+=X;
	}
      }else{
	//big
	updated[big_id[K]]+=X;
      }
    }else{
      assert(0);
    }
  }
  return 0;
}