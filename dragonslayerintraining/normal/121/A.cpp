#include <iostream>

long long bintolucky(long long len,long long bin){
  long long num=0;
  for(long long k=len-1;k>=0;k--){
    num=num*10+((bin&(1<<k))?7:4);
  }
  return num;
}

int main(){
  long long L,R;
  std::cin>>L>>R;
  long long sum=0;
  for(long long d=1;d<=10;d++){
    for(long long k=0;k<(1<<d);k++){
      long long lucky=bintolucky(d,k);
      if(lucky>=L){
	long long upper=std::min(lucky,R);
	sum+=(upper-L+1)*lucky;
	L=upper+1;
      }
    }
  }
  std::cout<<sum<<std::endl;
  return 0;
}