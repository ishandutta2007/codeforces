#include <iostream>
#include <set>

int N;

int sidecnt=0;
std::set<int> lens;

int main(){
  std::cin>>N;
  for(int i=0;i<N;i++){
    int A;
    std::cin>>A;
    if(lens.count(A)){
      lens.erase(A);
      sidecnt++;
    }else{
      lens.insert(A);
    }
  }
  std::cout<<sidecnt/2<<std::endl;
  return 0;
}