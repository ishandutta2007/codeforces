#include <iostream>

int first[10],second[10];

bool test(int first[10],int second[10]){
  int left=0;
  for(int i=0;i<10;i++){
    if(left<first[i]){
      return false;
    }
    left-=first[i];
    left+=second[i];
  }
  return true;
}

int main(){
  int N;
  std::cin>>N;
  std::string str;
  std::cin>>str;
  for(int i=0;i<N;i++){
    first[str[i]-'0']++;
  }
  for(int i=N;i<N*2;i++){
    second[str[i]-'0']++;
  }
  if(test(first,second)||test(second,first)){
    std::cout<<"YES"<<std::endl;
  }else{
    std::cout<<"NO"<<std::endl;
  }
  return 0;
}