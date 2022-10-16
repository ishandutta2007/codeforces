#include <iostream>
#include <map>

std::map<int,int> cnt;

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    int A;
    std::cin>>A;
    cnt[A]++;
  }
  if((cnt.size()==2)&&(cnt.begin()->second*2==N)){
    std::cout<<"YES"<<std::endl;
    std::cout<<cnt.begin()->first<<" "<<cnt.rbegin()->first<<std::endl;
  }else{
    std::cout<<"NO"<<std::endl;
  }
  return 0;
}