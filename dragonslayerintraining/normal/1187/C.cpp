#include <cstdio>
#include <set>
#include <algorithm>

std::set<int> dec;// a_i maybe >= a_i+1

int as[1000005];
int ts[1000005];
int ls[1000005];
int rs[1000005];

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=1;i<=N;i++){
    dec.insert(i);
  }
  for(int i=0;i<M;i++){
    scanf("%d %d %d",&ts[i],&ls[i],&rs[i]);
    if(ts[i]==1){
      for(auto it=dec.lower_bound(ls[i]);*it<rs[i];it=dec.lower_bound(ls[i])){
	dec.erase(it);
      }
    }
  }
  for(int i=0;i<M;i++){
    if(ts[i]==0){
      auto it=dec.lower_bound(ls[i]);
      if(*it>=rs[i]){
	printf("NO\n");
	return 0;
      }
    }
  }
  for(int i=0;i<N;i++){
    as[i]=N-i;
  }
  int prev=0;
  for(int x:dec){
    std::reverse(as+prev,as+x);
    prev=x;
  }
  printf("YES\n");
  for(int i=0;i<N;i++){
    if(i) printf(" ");
    printf("%d",as[i]);
  }
  printf("\n");
  return 0;
}