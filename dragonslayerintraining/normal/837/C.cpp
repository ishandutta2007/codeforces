#include <iostream>

int N,X,Y;
int xs[100],ys[100];

int best=0;

void test(int x0,int y0,int x1,int y1){
  //std::cerr<<x0<<","<<y0<<","<<x1<<","<<y1<<std::endl;
  if((x0+x1<=X)&&(y0<=Y)&&(y1<=Y)){
    best=std::max(best,x0*y0+x1*y1);
  }
  if((y0+y1<=Y)&&(x0<=X)&&(x1<=X)){
    best=std::max(best,x0*y0+x1*y1);
  }
}

int main(){
  std::cin>>N>>X>>Y;
  for(int i=0;i<N;i++){
    std::cin>>xs[i]>>ys[i];
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<i;j++){
      test(xs[i],ys[i],xs[j],ys[j]);
      test(xs[i],ys[i],ys[j],xs[j]);
      test(ys[i],xs[i],xs[j],ys[j]);
      test(ys[i],xs[i],ys[j],xs[j]);
    }
  }
  std::cout<<best<<std::endl;
  return 0;
}