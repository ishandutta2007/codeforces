#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

int main(){
  int A,B;
  std::cin>>A;
  {
    std::string base;
    std::cin>>base;
    if(!sscanf(base.c_str(),"%d",&B)){
      B=0;
    }
  }
  std::string num;
  std::cin>>num;
  long long val=0;
  for(int i=0;i<num.length();i++){
    if(std::isdigit(num[i])){
      val=val*A+num[i]-'0';
    }else{
      val=val*A+num[i]-'A'+10;
    }
  }
  if(B){
    std::vector<int> out;
    while(val>0){
      out.push_back(val%B);
      val/=B;
    }
    std::reverse(out.begin(),out.end());
    for(int i=0;i<out.size();i++){
      if(out[i]<10){
	std::cout<<char(out[i]+'0');
      }else{
	std::cout<<char(out[i]+'A'-10);
      }
    }
    if(out.size()==0){
      std::cout<<0;
    }
    std::cout<<std::endl;
  }else{
    switch(val/1000){
    case 0:break;
    case 1:std::cout<<"M";break;
    case 2:std::cout<<"MM";break;
    case 3:std::cout<<"MMM";break;
    }
    switch(val/100%10){
    case 0:break;
    case 1:std::cout<<"C";break;
    case 2:std::cout<<"CC";break;
    case 3:std::cout<<"CCC";break;
    case 4:std::cout<<"CD";break;
    case 5:std::cout<<"D";break;
    case 6:std::cout<<"DC";break;
    case 7:std::cout<<"DCC";break;
    case 8:std::cout<<"DCCC";break;
    case 9:std::cout<<"CM";break;
    }
    switch(val/10%10){
    case 0:break;
    case 1:std::cout<<"X";break;
    case 2:std::cout<<"XX";break;
    case 3:std::cout<<"XXX";break;
    case 4:std::cout<<"XL";break;
    case 5:std::cout<<"L";break;
    case 6:std::cout<<"LX";break;
    case 7:std::cout<<"LXX";break;
    case 8:std::cout<<"LXXX";break;
    case 9:std::cout<<"XC";break;
    }
    switch(val%10){
    case 0:break;
    case 1:std::cout<<"I";break;
    case 2:std::cout<<"II";break;
    case 3:std::cout<<"III";break;
    case 4:std::cout<<"IV";break;
    case 5:std::cout<<"V";break;
    case 6:std::cout<<"VI";break;
    case 7:std::cout<<"VII";break;
    case 8:std::cout<<"VIII";break;
    case 9:std::cout<<"IX";break;
    }
    std::cout<<std::endl;
  }
  return 0;
}