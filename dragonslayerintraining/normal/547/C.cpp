#include <cstdio>
#include <vector>
#include <stdint.h>

int N,Q;
int as[200000];

std::vector<int> factors[500001];
int sqr[500001];
int numfacts[500001];


int cnt[500001];

int64_t query=0;

void insert(int V){
  for(int fact:factors[V]){
    if(numfacts[fact]%2==0){
      query+=cnt[fact];
    }else{
      query-=cnt[fact];
    }
    cnt[fact]++;
  }
}

void erase(int V){
  for(int fact:factors[V]){
    --cnt[fact];
    if(numfacts[fact]%2==0){
      query-=cnt[fact];
    }else{
      query+=cnt[fact];
    }
  }
}

int main(){
  for(int i=2;i*i<=500000;i++){
    for(int k=i*i;k<=500000;k+=i*i){
      sqr[k]=1;
    }
  }
  for(int i=2;i<=500000;i++){
    if(numfacts[i]==0){
      for(int k=i;k<=500000;k+=i){
	numfacts[k]++;
      }
    }
  }
  for(int i=1;i<=500000;i++){
    if(sqr[i]==0){
      for(int k=i;k<=500000;k+=i){
	factors[k].push_back(i);
      }
    }
  }
  scanf("%d %d",&N,&Q);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  for(int i=0;i<Q;i++){
    int X;
    scanf("%d",&X);
    X--;
    if(as[X]>0){
      insert(as[X]);
    }else{
      erase(-as[X]);
    }
    as[X]=-as[X];
    printf("%I64d\n",query);
  }
  return 0;
}