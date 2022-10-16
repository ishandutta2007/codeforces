#include <iostream>
#include <algorithm>

int best=1e9;

void test(std::string str){
  int left=0,right=str.length()-1;
  int cnt=0;
  while(left<right){
    if(str[left]=='H'){left++;continue;}
    if(str[right]=='T'){right--;continue;}
    std::swap(str[left],str[right]);
    cnt++;
  }
  best=std::min(best,cnt);
}

int main(){
  int N;
  std::string str;
  std::cin>>N>>str;
  for(int i=0;i<N;i++){
    test(str);
    std::rotate(str.begin(),str.begin()+1,str.end());
  }
  std::cout<<best<<std::endl;
  return 0;
}