#include <iostream>
#include <algorithm>

int best=0;

void test(int a,int b,int c){
  if(a+b>c){
    best=std::max(best,2);
  }else if(a+b==c){
    best=std::max(best,1);
  }else{
    best=std::max(best,0);
  }
}

int main(){
  int a[4];
  std::cin>>a[0]>>a[1]>>a[2]>>a[3];
  std::sort(a,a+4);
  test(a[0],a[1],a[2]);
  test(a[0],a[1],a[3]);
  test(a[0],a[2],a[3]);
  test(a[1],a[2],a[3]);
  switch(best){
  case 0:std::cout<<"IMPOSSIBLE"<<std::endl;break;
  case 1:std::cout<<"SEGMENT"<<std::endl;break;
  case 2:std::cout<<"TRIANGLE"<<std::endl;break;
  }
  return 0;
}