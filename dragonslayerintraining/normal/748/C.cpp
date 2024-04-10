#include <iostream>

int main(){
  int N;
  std::string str;
  std::cin>>N>>str;
  char horiz='\0',verti='\0';
  int cnt=1;
  for(int i=0;i<N;i++){
    if((str[i]=='L')||(str[i]=='R')){
      if(horiz=='\0'){
	horiz=str[i];
      }else if(horiz!=str[i]){
	horiz=str[i];
	verti='\0';
	cnt++;
      }
    }else if((str[i]=='U')||(str[i]=='D')){
      if(verti=='\0'){
	verti=str[i];
      }else if(verti!=str[i]){
	horiz='\0';
	verti=str[i];
	cnt++;
      }
    }
  }
  std::cout<<cnt<<std::endl;
  return 0;
}