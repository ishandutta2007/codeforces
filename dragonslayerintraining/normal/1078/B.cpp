#include <cstdio>
#include <bitset>
#include <map>
#include <cassert>

std::bitset<100001> any[101];
std::bitset<100001> nae[101];

int as[101];

int main(){
  int N;
  int sum=0;
  scanf("%d",&N);
  std::map<int,int> freq;
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    freq[A]++;
    sum+=A;
  }
  any[0].set(0);
  for(auto it:freq){
    int A=it.first;
    int cnt=it.second;
    //don't use (0,0)
    for(int k=2;k<=100;k++){
      nae[k]|=(any[k-1]<<A);
    }
    for(int i=1;i<cnt;i++){
      for(int k=100;k>0;k--){
	nae[k]|=(nae[k-1]<<A);
      }
    }
    for(int i=0;i<cnt;i++){
      for(int k=100;k>0;k--){
	any[k]|=(any[k-1]<<A);
      }
    }
  }
  int best=0;
  for(int k=1;k<=N;k++){
    for(int i=0;i<=sum;i++){
      /*
      assert(!nae[k].test(i)||any[k].test(i));
      if(nae[k].test(i)) printf("NAE k=%d, w=%d\n",k,i);
      else if(any[k].test(i)) printf("ANY k=%d, w=%d\n",k,i);
      */
      int ans=0;
      if(any[k].test(i)&&!nae[k].test(i)) ans+=k;
      if(any[N-k].test(sum-i)&&!nae[N-k].test(sum-i)) ans+=(N-k);
      best=std::max(best,ans);
    }
  }
  printf("%d\n",best);
  return 0;
}