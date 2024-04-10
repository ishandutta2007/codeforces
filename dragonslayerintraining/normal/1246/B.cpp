#include <cstdio>
#include <vector>
#include <map>

int maxf[100005];//max prime factor

int main(){
  for(int i=2;i<=100000;i++){
    if(!maxf[i]){
      for(int j=i;j<=100000;j+=i){
	maxf[j]=i;
      }
    }
  }
  int N,K;
  scanf("%d %d",&N,&K);
  std::map<std::vector<std::pair<int,int> >,int> freq;
  long long ans=0;
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    std::map<int,int> factors;
    while(A!=1){
      factors[maxf[A]]++;
      A/=maxf[A];
    }
    std::vector<std::pair<int,int> > hash;
    std::vector<std::pair<int,int> > ihash;
    for(auto it:factors){
      int p=it.first,v=it.second%K;
      if(v){
	hash.push_back({p,v});
	ihash.push_back({p,K-v});
      }
    }
    ans+=freq[ihash];
    freq[hash]++;
  }
  printf("%lld\n",ans);
}