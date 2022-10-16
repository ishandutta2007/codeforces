#include <cstdio>
#include <random>
#include <chrono>

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

long long as[300005];
long long bs[300005];

int main(){
  long long MOD=rng();
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    as[A]++;
  }
  for(int i=1;i<=300000;i++){
    for(int j=i*2;j<=300000;j+=i){
      as[i]=(as[i]+as[j])%MOD;
    }
  }
  for(int size=1;size<=7;size++){
    for(int i=1;i<=300000;i++){
      bs[i]=1;
      for(int k=0;k<size;k++){
	bs[i]=1LL*bs[i]*as[i]%MOD;
      }
    }
    for(int i=300000;i>=1;i--){
      for(int j=i*2;j<=300000;j+=i){
	bs[i]=(bs[i]-bs[j]+MOD)%MOD;
      }
    }
    if(bs[1]){
      printf("%d\n",size);
      return 0;
    }
  }
  printf("-1\n");
}