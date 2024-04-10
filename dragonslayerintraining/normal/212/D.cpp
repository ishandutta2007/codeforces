#include <cstdio>
#include <stack>
#include <stdint.h>
#include <iomanip>

int64_t as[1000000];
int64_t left[1000000];
int64_t right[1000000];

int64_t mult_delta[1000001];
int64_t add_delta[1000001];

double sums[1000000];

int main(){
  int N;
  scanf("%d",&N);
  for(int64_t i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    as[i]=A;
  }
  {
    std::stack<std::pair<int64_t,int64_t> > min;
    min.push(std::make_pair(-1e9,-1));
    for(int64_t i=0;i<N;i++){
      while(min.top().first>=as[i]){
	min.pop();
      }
      left[i]=i-min.top().second-1;
      min.push(std::make_pair(as[i],i));
    }
  }
  {
    std::stack<std::pair<int64_t,int64_t> > min;
    min.push(std::make_pair(-1e9,N));
    for(int64_t i=N-1;i>=0;i--){
      //this one does not include equality to account for duplicate ekements.
      while(min.top().first>as[i]){
	min.pop();
      }
      right[i]=min.top().second-i-1;
      min.push(std::make_pair(as[i],i));
    }
  }

  for(int64_t i=0;i<N;i++){
    int64_t a=std::min(left[i],right[i]);
    int64_t b=std::max(left[i],right[i]);
    //events[0].push_back(event(i,1,1));
    //events[a].push_back(event(i,0,a+1));
    //events[b].push_back(event(i,-1,a+b+1));
    //events[a+b].push_back(event(i,0,0));
    //do diffs instead
    mult_delta[0]+=as[i];add_delta[0]+=as[i]*1;
    mult_delta[a]-=as[i];add_delta[a]+=as[i]*a;
    mult_delta[b]-=as[i];add_delta[b]+=as[i]*b;
    mult_delta[a+b+1]+=as[i];add_delta[a+b+1]-=as[i]*(a+b+1);
  }
  int64_t mult=0,add=0;
  for(int64_t k=0;k<=N;k++){
    mult+=mult_delta[k];
    add+=add_delta[k];
    sums[k]=mult*k+add;
  }
  int M;
  scanf("%d",&M);
  for(int64_t i=0;i<M;i++){
    int K;
    scanf("%d",&K);
    printf("%.10lf\n",sums[K-1]/double(N-K+1));
  }
  return 0;
}