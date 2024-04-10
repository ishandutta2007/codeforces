#include <cstdio>
#include <random>
#include <chrono>
#include <vector>
#include <algorithm>

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

int gcd(int a,int b){
  return b?gcd(b,a%b):a;
}

int as[100005];

int assign[100005];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  std::vector<int> ord;
  for(int i=0;i<N;i++){
    ord.push_back(i);
  }
  long long t=clock();
  while(clock()-t<0.4*CLOCKS_PER_SEC){
    std::shuffle(ord.begin(),ord.end(),rng);
    int g1=0,g2=0;
    for(int i:ord){
      int tmp=gcd(g1,as[i]);
      if(tmp!=g1){
	assign[i]=1;
	g1=tmp;
      }else{
	assign[i]=2;
	g2=gcd(g2,as[i]);
      }
    }
    if(g1==1&&g2==1){
      printf("YES\n");
      for(int i=0;i<N;i++){
	printf("%d\n",assign[i]);
      }
      return 0;
    }
  }
  printf("NO\n");
}