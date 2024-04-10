#include <cstdio>
#include <set>

int has[200005];
int cap[200005];

std::set<int> unfull;

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&cap[i]);
    unfull.insert(i);
  }
  int Q;
  scanf("%d",&Q);
  while(Q-->0){
    int T;
    scanf("%d",&T);
    if(T==1){
      int P,X;
      scanf("%d %d",&P,&X);
      P--;
      while(X>0){
	auto it=unfull.lower_bound(P);
	if(it==unfull.end()) break;
	P=*it;
	int use=std::min(cap[P]-has[P],X);
	has[P]+=use;
	X-=use;
	if(has[P]==cap[P]){
	  unfull.erase(P);
	}
      }
    }else{
      int K;
      scanf("%d",&K);
      K--;
      printf("%d\n",has[K]);
    }
  }
  return 0;
}