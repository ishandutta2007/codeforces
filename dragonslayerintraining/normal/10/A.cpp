#include <iostream>

int main(){
  int n,p1,p2,p3,t1,t2;
  std::cin>>n>>p1>>p2>>p3>>t1>>t2;
  int power=0;
  int curtime=0;
  for(int i=0;i<n;i++){
    int l,r;
    std::cin>>l>>r;
    if(curtime==0){
      curtime=l;
    }
    if(l-curtime<t1){
      power+=(l-curtime)*p1;
    }else{
      power+=p1*t1;
      curtime+=t1;
      if(l-curtime<t2){
	power+=(l-curtime)*p2;
      }else{
	power+=p2*t2;
	curtime+=t2;
	power+=(l-curtime)*p3;
      }
    }
    power+=(r-l)*p1;
    curtime=r;
  }
  std::cout<<power<<std::endl;
  return 0;
}