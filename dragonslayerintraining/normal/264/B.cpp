#include <iostream>

int factor[100001];
int longest[100001];

int main(){
  for(int i=2;i<=100000;i++){
    if(factor[i]==0){
      for(int k=i;k<=100000;k+=i){
	factor[k]=i;
      }
    }
  }
  int N;
  std::cin>>N;
  int ans=1;
  for(int i=0;i<N;i++){
    int A;
    std::cin>>A;
    int best=0;
    for(int X=A;X>1;X/=factor[X]){
      best=std::max(best,longest[factor[X]]+1);
    }
    ans=std::max(ans,best);
    for(int X=A;X>1;X/=factor[X]){
      longest[factor[X]]=std::max(longest[factor[X]],best);
    }
  }
  std::cout<<ans<<std::endl;
  return 0;
}