#include <cstdio>

const long long HUGE=1e9;

int main(){
  long long as[3];
  scanf("%lld %lld %lld",&as[0],&as[1],&as[2]);
  printf("First\n");
  printf("%lld\n",HUGE);
  fflush(stdout);
  long long pile;
  scanf("%lld",&pile);
  if(pile==0) return 0;
  as[pile-1]+=HUGE;
  long long add=as[pile-1]*2-as[pile%3]-as[(pile+1)%3];
  printf("%lld\n",add);
  fflush(stdout);
  long long pile2;
  scanf("%lld",&pile2);
  if(pile2==0) return 0;
  as[pile2-1]+=add;
  printf("%lld\n",as[pile2-1]-as[pile-1]);
  fflush(stdout);
}