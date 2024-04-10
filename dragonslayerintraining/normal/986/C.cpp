#include <cstdio>
#include <algorithm>
#include <set>

int as[1<<22];
int rep[1<<22];
int trickle[1<<22];
int uf[1<<22];

int find(int a){
  return (a==uf[a])?a:(uf[a]=find(uf[a]));
}

void merge(int a,int b){
  if(uf[a]==-1){
    uf[a]=uf[b];
    return;
  }
  if(uf[b]==-1){
    uf[b]=uf[a];
    return;
  }
  uf[find(a)]=find(b);
}

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  std::fill(rep,rep+(1<<N),-1);
  std::fill(uf,uf+(1<<N),-1);
  int full=(1<<N)-1;
  for(int i=0;i<M;i++){
    int A;
    scanf("%d",&A);
    as[A]++;
    rep[A]=A;
    uf[A]=A;
  }
  for(int k=0;k<N;k++){
    for(int i=0;i<(1<<N);i++){
      if((i&(1<<k))==0){
	rep[i|(1<<k)]=std::max(rep[i|(1<<k)],rep[i]);
      }
    }
  }
  for(int i=0;i<(1<<N);i++){
    if(as[i]&&rep[full-i]>=0){
      merge(i,rep[full-i]);
      trickle[full-i]++;
      //printf("MERGE %d with %d\n",i,rep[full-i]);
    }
  }
  for(int k=0;k<N;k++){
    for(int i=0;i<(1<<N);i++){
      if((i&(1<<k))==0){
	trickle[i]+=trickle[i|(1<<k)];
      }
    }
  }
  for(int k=0;k<N;k++){
    for(int i=0;i<(1<<N);i++){
      if((i&(1<<k))==0){
	if(trickle[i|(1<<k)]&&rep[i]>=0){
	  merge(i,i|(1<<k));
	}
      }
    }
  }
  std::set<int> distinct;
  for(int i=0;i<(1<<N);i++){
    if(as[i]){
      distinct.insert(find(i));
    }
  }
  /*
  for(int i=0;i<(1<<N);i++){
    printf("%d: %d %d %d %d\n",i,as[i],rep[i],trickle[i],uf[i]>=0?find(uf[i]):-1);
  }
  */
  printf("%d\n",(int)distinct.size());
  return 0;
}