#include <iostream>
#include <cmath>
#include <iomanip>

int main(){
  double R,X1,Y1,X2,Y2;
  std::cin>>R>>X1>>Y1>>X2>>Y2;
  X2-=X1,Y2-=Y1;
  if(X2*X2+Y2*Y2>=R*R){
    std::cout<<X1<<" "<<Y1<<" "<<R<<std::endl;
    return 0;
  }
  if(X2!=0||Y2!=0){
    double magn=std::sqrt(X2*X2+Y2*Y2);
    double X3=-X2/magn*R;
    double Y3=-Y2/magn*R;
    std::cout<<std::fixed<<std::setprecision(10)<<(X1+(X2+X3)/2)<<" "
	     <<std::fixed<<std::setprecision(10)<<(Y1+(Y2+Y3)/2)<<" "
	     <<std::fixed<<std::setprecision(10)<<((R+magn)/2)<<std::endl;
  }else{
    std::cout<<std::fixed<<std::setprecision(10)<<(X1+R/2)<<" "
	     <<std::fixed<<std::setprecision(10)<<(Y1)<<" "
	     <<std::fixed<<std::setprecision(10)<<(R/2)<<std::endl;
  }
  return 0;
}