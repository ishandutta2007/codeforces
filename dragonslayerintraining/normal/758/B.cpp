#include <iostream>

int R,B,Y,G;
int dead[4];

int main(){
  std::string str;
  std::cin>>str;
  for(int i=0;i<str.length();i++){
    switch(str[i]){
    case 'R':R=i%4;break;
    case 'B':B=i%4;break;
    case 'Y':Y=i%4;break;
    case 'G':G=i%4;break;
    case '!':dead[i%4]++;break;
    }
  }
  std::cout<<dead[R]<<" "<<dead[B]<<" "<<dead[Y]<<" "<<dead[G]<<std::endl;
  return 0;
}