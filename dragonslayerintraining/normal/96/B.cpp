#include <iostream>

long long _nextlucky(long long N,bool& jump){
  if(N==0){
    return 0;
  }
  if(N%10<=4){
    long long ret= _nextlucky(N/10,jump)*10+4;
    if(N%10<4){
      jump=true;
    }
    return ret;
  }else if(N%10<=7){
    long long ret=_nextlucky(N/10,jump)*10;
    ret=jump?ret+4:ret+7;
    if(N%10<7){
      jump=true;
    }
    return ret;
  }else{
    long long ret=_nextlucky(N/10+1,jump)*10+4;
    jump=true;
    return ret;
  }
}

long long nextlucky(long long N){
  bool jump=false;
  return _nextlucky(N,jump);
}

long long issuperlucky(long long N){
  long long cnt4=0,cnt7=0;
  while(N>0){
    switch(N%10){
    case 4:cnt4++;break;
    case 7:cnt7++;break;
    }
    N/=10;
  }
  return cnt4==cnt7;
}

int main(){
  long long N;
  std::cin>>N;
  N=nextlucky(N);
  while(!issuperlucky(N)){
    N=nextlucky(N+1);
  }
  std::cout<<N<<std::endl;
  return 0;
}