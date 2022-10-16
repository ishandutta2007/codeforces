#include <iostream>
#include <vector>

int test(int len,bool same){
  if(len>=2) return 2;
  if(!same) return 1;
  return len?2:0;
}

int main(){
  int N;
  std::string str;
  
  std::cin>>N>>str;
  std::vector<int> is;
  
  for(int i=0;i<N;i++){
    if(str[i]!='?'){
      is.push_back(i);
    }
  }
  if(is.empty()){
    std::cout<<"YES"<<std::endl;
    return 0;
  }
  bool two=false;
  if((is.front()>0)||(is.back()<str.length()-1)){
    two=true;
  }
  
  for(int i=0;i+1<is.size();i++){
    bool same=(str[is[i]]==str[is[i+1]]);
    int len=is[i+1]-is[i]-1;
    switch(test(len,same)){
    case 0:std::cout<<"No"<<std::endl;return 0;
    case 1:break;
    case 2:two=true;break;
    }
  }
  if(two){
    std::cout<<"Yes"<<std::endl;
  }else{
    std::cout<<"No"<<std::endl;
  }
  return 0;
}