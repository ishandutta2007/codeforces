#include <cstdio>
#include <vector>
#include <algorithm>
#include <cassert>
#include <stdint.h>

std::vector<std::pair<int64_t,int64_t> > people;
int64_t N,S;

int64_t best=0;

void eat_right(int64_t delta,int64_t i,int64_t rem){
  for(;i<people.size();i++){
    int64_t K=std::min(rem,people[i].second);
    delta+=people[i].first*K;
    rem-=K;
  }
  //assert(rem==0);
  //fprintf(stderr,"right.delta=%I64d\n",delta);
  best=std::max(best,delta);
}

void eat_left(int64_t delta,int64_t i,int64_t rem){
  for(i--;i>=0;i--){
    int64_t K=std::min(rem,people[i].second);
    delta-=people[i].first*K;
    rem-=K;
  }
  //assert(rem==0);
  //fprintf(stderr,"left.delta=%I64d\n",delta);
  best=std::max(best,delta);
}

void solve(){
  int64_t eat=0;
  int64_t delta=0;
  int64_t i;
  for(i=0;i<people.size();i++){
    if(people[i].first>0){
      eat+=people[i].second;
      delta+=people[i].first*people[i].second;
    }else{
      break;
    }
  }
  eat_left(delta,i,eat%S);
  eat_right(delta,i,(S-eat%S)%S);
}

int main(){ 
  scanf("%I64d %I64d",&N,&S);
  int64_t eat=0;
  int64_t happy=0;
  for(int64_t i=0;i<N;i++){
    int64_t s,a,b;
    scanf("%I64d %I64d %I64d",&s,&a,&b);
    happy+=a*s;
    eat+=s;
    people.emplace_back(b-a,s);
  }
  people.emplace_back(0,(S-eat%S)%S);
  
  std::sort(people.begin(),people.end());
  std::reverse(people.begin(),people.end());
  // for(int64_t i=0;i<people.size();i++){
  //   fprintf(stderr,"+%I64d x%I64d\n",people[i].first,people[i].second);
  // }
  solve();
  //fprintf(stderr,"%I64d+%I64d=%I64d\n",happy,best,happy+best);
  printf("%I64d\n",happy+best);
  return 0;
}