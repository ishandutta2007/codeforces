#include <iostream>
#include <vector>

std::vector<int> out;

int main(){
  int N;
  std::cin>>N;
  int reports=0;
  int neg=0;
  for(int i=0;i<N;i++){
    int A;
    std::cin>>A;
    if(A>=0){
      reports++;
    }else if(neg==2){
      out.push_back(reports);
      reports=1;
      neg=1;
    }else{
      reports++;
      neg++;
    }
  }
  if(reports>0){
    out.push_back(reports);
  }
  std::cout<<out.size()<<std::endl;
  for(int i=0;i<out.size();i++){
    if(i>0){
      std::cout<<" ";
    }
    std::cout<<out[i];
  }
  std::cout<<std::endl;
  return 0;
}