#include <iostream>
#include <vector>

int main(){
  int N,M;
  std::cin>>N>>M;
  std::string S,T;
  std::cin>>S>>T;
  int best=1e9;
  int index=0;
  for(int start=0;start<=T.size()-S.size();start++){
    int mismatch=0;
    for(int i=0;i<S.size();i++){
      if(S[i]!=T[start+i]){
	mismatch++;
      }
    }
    if(mismatch<best){
      best=mismatch;
      index=start;
    }
  }
  std::cout<<best<<std::endl;
  std::vector<int> diff;
  for(int i=0;i<S.size();i++){
    if(S[i]!=T[index+i]){
      diff.push_back(i+1);
    }
  }
  for(int i=0;i<diff.size();i++){
    if(i>0){
      std::cout<<" ";
    }
    std::cout<<diff[i];
  }
  std::cout<<std::endl;
  return 0;
}