#include <iostream>

bool isright(int x0,int y0,int x1,int y1){
  return (x0*x1+y0*y1==0);
}

bool isright(int x0,int y0,int x1,int y1,int x2,int y2){
  if((x0==x1)&&(y0==y1)){return false;}
  if((x0==x2)&&(y0==y2)){return false;}
  if((x1==x2)&&(y1==y2)){return false;}
  return (isright(x0-x1,y0-y1,x0-x2,y0-y2)||
	  isright(x0-x1,y0-y1,x1-x2,y1-y2)||
	  isright(x0-x2,y0-y2,x1-x2,y1-y2));
}

int main(){
  int x0,y0,x1,y1,x2,y2;
  std::cin>>x0>>y0>>x1>>y1>>x2>>y2;
  if(isright(x0,y0,x1,y1,x2,y2)){
    std::cout<<"RIGHT"<<std::endl;
  }else if(isright(x0+1,y0,x1,y1,x2,y2)||
	   isright(x0-1,y0,x1,y1,x2,y2)||
	   isright(x0,y0+1,x1,y1,x2,y2)||
	   isright(x0,y0-1,x1,y1,x2,y2)||
	   isright(x0,y0,x1+1,y1,x2,y2)||
	   isright(x0,y0,x1-1,y1,x2,y2)||
	   isright(x0,y0,x1,y1+1,x2,y2)||
	   isright(x0,y0,x1,y1-1,x2,y2)||
	   isright(x0,y0,x1,y1,x2+1,y2)||
	   isright(x0,y0,x1,y1,x2-1,y2)||
	   isright(x0,y0,x1,y1,x2,y2+1)||
	   isright(x0,y0,x1,y1,x2,y2-1)){
    std::cout<<"ALMOST"<<std::endl;
  }else{
    std::cout<<"NEITHER"<<std::endl;
  }
  return 0;
}