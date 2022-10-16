#include <iostream>
#include <algorithm>

std::string A,B;
int match[2][100000];

void subsequence(int* arr){
  int curr=0;
  for(int i=0;i<A.size();i++){
    if(A[i]==B[curr]){
      curr++;
    }
    arr[i]=curr;
  }
}

int main(){
  std::cin>>A>>B;
  for(int i=0;i<2;i++){
    subsequence(match[i]);
    std::reverse(A.begin(),A.end());
    std::reverse(B.begin(),B.end());
  }
  std::reverse(match[1],match[1]+A.size());
  std::pair<int,int> best(match[1][0],0);
  for(int i=0;i<A.size();i++){
    best=std::max(best,std::make_pair(match[0][i]+match[1][i+1],match[0][i]));
  }
  if(best.first==0){
    std::cout<<"-"<<std::endl;
    return 0;
  }else if(best.first>=B.size()){
    std::cout<<B<<std::endl;
    return 0;
  }
  for(int i=0;i<best.second;i++){
    std::cout<<B[i];
  }
  for(int i=B.size()-best.first+best.second;i<B.size();i++){
    std::cout<<B[i];
  }
  std::cout<<std::endl;
  return 0;
}