#include <cstdio>
#include <vector>
#include <map>

int main(){
  int T;
  scanf("%d",&T);
  while(T-->0){
    int N;
    scanf("%d",&N);
    std::map<int,int> cnt;
    for(int i=0;i<N;i++){
      int A;
      scanf("%d",&A);
      cnt[A]++;
    }
    std::vector<int> lens;
    for(auto it:cnt){
      if(it.second>=2) lens.push_back(it.first);
      if(it.second>=4) lens.push_back(it.first);
    }
    int a=1,b=2e4;
    for(int i=0;i+1<lens.size();i++){
      if(lens[i+1]*a<lens[i]*b){
	a=lens[i],b=lens[i+1];
      }
    }
    printf("%d %d %d %d\n",a,a,b,b);
  }
  return 0;
}