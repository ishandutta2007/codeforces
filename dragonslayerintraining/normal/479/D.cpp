#include <iostream>

long long N,L,X,Y;
long long as[100005];
long long bs[100005];

long long canmeasure(long long len,long long min=0){
  long long i=0,j=0;
  long long ac=0;
  while(j<N){
    if(ac<len){
      ac+=(as[j+1]-as[j]);
      j++;
    }else if(ac>len){
      ac-=(as[i+1]-as[i]);
      i++;
    }else{
      if(as[i]<min){
	ac+=(as[j+1]-as[j]);
	j++;
      }else{
	return as[i];
      }
    }
  }
  return -1;
}

int main(){
  std::cin>>N>>L>>X>>Y;
  for(long long i=0;i<N;i++){
    std::cin>>as[i];
  }
  bool canmeasureX=(canmeasure(X)>=0);
  bool canmeasureY=(canmeasure(Y)>=0);
  if(canmeasureX&&canmeasureY){
    std::cout<<0<<std::endl;
    return 0;
  }
  if(canmeasureX){
    std::cout<<1<<std::endl;
    std::cout<<Y<<std::endl;
    return 0;
  }
  if(canmeasureY){
    std::cout<<1<<std::endl;
    std::cout<<X<<std::endl;
    return 0;
  }
  {
    long long Z=canmeasure(X+Y);
    if(Z>=0){
      std::cout<<1<<std::endl;
      std::cout<<Z+X<<std::endl;
      return 0;
    }
  }
  {
  long long Z=canmeasure(Y-X);
  if((Z>=0)&&(Z+Y<=L)){
    std::cout<<1<<std::endl;
    std::cout<<Z+Y<<std::endl;
    return 0;
  }
  }
  {
  long long Z=canmeasure(Y-X,X);
  if((Z>=0)&&(Z-X>=0)){
    std::cout<<1<<std::endl;
    std::cout<<Z-X<<std::endl;
    return 0;
  }
  }
  std::cout<<2<<std::endl;
  std::cout<<X<<" "<<Y<<std::endl;
  return 0;
}