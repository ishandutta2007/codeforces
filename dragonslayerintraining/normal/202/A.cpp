#include <iostream>
#include <algorithm>

std::string pal;
int main(){
  std::string str;
  std::cin>>str;
  int L=0,R=str.length()-1;
  int max='\0';
  while(true){
    int first=R+1,last=L-1;
    for(int i=L;i<=R;i++){
      if(str[i]>max){
	max=str[i];
	first=last=i;
      }else if(str[i]==max){
	if(first==R+1){
	  first=i;
	}
	last=i;
      }
    }
    if(first<last){
      pal+=max;
      L=first+1,R=last-1;
    }else if(first>last){
      std::cout<<pal;
      std::reverse(pal.begin(),pal.end());
      std::cout<<pal<<std::endl;
      return 0;
    }else{
      std::cout<<pal<<char(max);
      std::reverse(pal.begin(),pal.end());
      std::cout<<pal<<std::endl;
      return 0;
    }
  }
  return 0;
}