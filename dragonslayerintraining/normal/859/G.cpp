#include <cstdio>
#include <vector>

std::vector<int> primes;
int sqr=1;

void factor(int N){
  int num=N;
  for(int i=2;i*i<=N;i++){
    if(num%i==0){
      num/=i;
      primes.push_back(i);
      while(num%i==0){
	num/=i;
	sqr*=i;
      }
    }
  }
  if(num>1){
    primes.push_back(num);
  }
}

int as[100000];
char str[100005];

int main(){
  int N;
  scanf("%d",&N);
  factor(N);
  scanf("%s",str);
  for(int i=0;i<N;i++){
    as[i]=str[i]-'0';
  }
  for(int p:primes){
    for(int r=0;r<sqr;r++){
      for(int i=r;i<N;i+=p*sqr){
	int first=as[i];
	for(int j=0;j<p;j++){
	  as[(i+N/p*j)%N]-=first;
	}
      }
    }
  }
  for(int i=0;i<N;i++){
    if(as[i]!=0){
      printf("NO\n");
      return 0;
    }
  }
  printf("YES\n");
  return 0;
}