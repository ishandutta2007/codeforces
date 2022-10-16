#include <cstdio>
#include <cstdlib>
#include <set>

int as[200005];
int ls[200005];
int rs[200005];

std::set<int> used;

void fail(){
  printf("NO\n");
  exit(0);
}

int main(){
  int N,Q;
  scanf("%d %d",&N,&Q);
  std::fill(ls+1,ls+Q+1,N+1);
  std::fill(rs+1,rs+Q+1,-1);
  int hide=-1;
  for(int i=1;i<=N;i++){
    scanf("%d",&as[i]);
    if(as[i]){
      used.insert(i);
      ls[as[i]]=std::min(ls[as[i]],i);
      rs[as[i]]=std::max(rs[as[i]],i);
    }else{
      hide=i;
    }
  }
  used.insert(N+1);
  
  for(int i=Q;i>=1;i--){
    if(ls[i]>rs[i]){
      if(hide==-1) fail();
      ls[i]=hide;
      rs[i]=hide;
    }else{
      for(auto it=used.lower_bound(ls[i]);*it<=rs[i];it=used.lower_bound(ls[i])){
	if(as[*it]!=i) fail();
	as[*it]=0;
	used.erase(it);
      }
      hide=ls[i];
    }
  }
  for(int i=1;i<=N;i++){
    used.insert(i);
  }
  for(int i=Q;i>=1;i--){
    for(auto it=used.lower_bound(ls[i]);*it<=rs[i];it=used.lower_bound(ls[i])){
      as[*it]=i;
      used.erase(it);
    }
  }
  int last=0;
  for(int i=1;i<=N;i++){
    if(as[i]==0&&last){
      as[i]=last;
    }else{
      last=as[i];
    }
  }
  last=0;
  for(int i=N;i>=1;i--){
    if(as[i]==0&&last){
      as[i]=last;
    }else{
      last=as[i];
    }
  }
  printf("YES\n");
  for(int i=1;i<=N;i++){
    if(i>1) printf(" ");
    printf("%d",as[i]);
  }
  printf("\n");
  return 0;
}