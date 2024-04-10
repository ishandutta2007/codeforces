#include <cstdio>
#include <bitset>

std::bitset<7001> base[7001];
std::bitset<7001> cancel[7001];
std::bitset<7001> sets[100005];

int sqrfree[7001];
int primes[7001];

int main(){
  for(int i=2;i<=7000;i++){
    primes[i]=true;
  }
  for(int i=1;i<=7000;i++){
    sqrfree[i]=true;
  }
  for(int i=2;i<=7000;i++){
    if(primes[i]){
      for(int j=i;j<=7000;j+=i){
	primes[j]=false;
      }
      for(int j=i*i;j<=7000;j+=i*i){
	sqrfree[j]=false;
      }
      //printf("PRIME %d\n",i);
    }
  }
  /*
  for(int i=0;i<=7000;i++){
    if(sqrfree[i]){
      printf("SQRFREE %d\n",i);
    }
  }
  */
  for(int i=1;i<=7000;i++){
    for(int j=i;j<=7000;j+=i){
      base[j].set(i);
    }
  }
  for(int i=1;i<=7000;i++){
    for(int j=1;i*j<=7000;j++){
      if(sqrfree[j]){
	cancel[i].set(i*j);
	//printf("CANCEL %d: %d\n",i,i*j);
      }
    }
  }
  int N,Q;
  scanf("%d %d",&N,&Q);
  while(Q-->0){
    int T,X,V,Y,Z;
    scanf("%d",&T);
    if(T==1){
      scanf("%d %d",&X,&V);
      sets[X]=base[V];
    }else if(T==2){
      scanf("%d %d %d",&X,&Y,&Z);
      sets[X]=sets[Y]^sets[Z];
    }else if(T==3){
      scanf("%d %d %d",&X,&Y,&Z);
      sets[X]=sets[Y]&sets[Z];
    }else{
      scanf("%d %d",&X,&V);
      printf("%d",(int)(sets[X]&cancel[V]).count()&1);
    }
  }
  printf("\n");
  return 0;
}