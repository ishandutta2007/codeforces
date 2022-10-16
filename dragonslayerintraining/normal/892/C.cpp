#include <cstdio>
#include <algorithm>

int gcd(int a,int b){
  return b?gcd(b,a%b):a;
}

int as[2000];

int main(){
  int N;
  scanf("%d",&N);
  int ones=0;
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
    ones+=(as[i]==1);
  }
  if(ones>0){
    printf("%d\n",N-ones);
    return 0;
  }

  int best=1e9;
  for(int i=0;i<N;i++){
    int g=0;
    for(int j=i;j<N;j++){
      g=gcd(g,as[j]);
      if(g==1){
	best=std::min(best,j-i);
	break;
      }
    }
  }
  if(best<1e9){
    printf("%d\n",best+N-1);
  }else{
    printf("-1\n");
  }
  return 0;
}