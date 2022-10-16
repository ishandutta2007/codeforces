#include <cstdio>
#include <set>
#include <algorithm>

unsigned int houses[200000];
unsigned int houses_cnt=0;

unsigned int stations[3];

bool test(unsigned int D){
  //fprintf(stderr,"test %u: ",D);
  unsigned int *p=houses;
  for(unsigned int i=0;i<3;i++){
    unsigned int *p2=std::upper_bound(houses,houses+houses_cnt,*p+D);
    if(p2==houses+houses_cnt){
      for(;i<3;i++){
	stations[i]=*p*2+D;
      }
      //fprintf(stderr,"%d %d %d\n",stations[0],stations[1],stations[2]);
      return true;
    }
    stations[i]=*p*2+D;
    p=p2;
  }
  //fprintf(stderr,"failed\n");
  return false;
}

void printhalf(unsigned int num){
  if(num%2==0){
    printf("%d.000000",num/2);
  }else{
    printf("%d.500000",num/2);
  }
}

int main(){
  std::set<unsigned int> hs;
  unsigned int N;
  scanf("%u",&N);
  for(unsigned int i=0;i<N;i++){
    unsigned int H;
    scanf("%d",&H);
    hs.insert(H);
  }
  for(std::set<unsigned int>::iterator
	it=hs.begin();it!=hs.end();it++){
    houses[houses_cnt++]=*it;
  }
    
  unsigned int low=-1,high=1e9;
  while(high-low>1){
    unsigned int mid=(low+high)/2;
    if(test(mid)){
      high=mid;
    }else{
      low=mid;
    }
  }
  test(high);
  printhalf(high);
  printf("\n");
  for(int i=0;i<3;i++){
    printhalf(stations[i]);
    if(i<2){
      printf(" ");
    }else{
      printf("\n");
    }
  }
  return 0;
}