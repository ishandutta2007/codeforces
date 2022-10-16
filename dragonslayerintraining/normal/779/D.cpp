#include <iostream>

std::string T,P;
int as[200005];
int rem[200005];

bool test(int stage){
  for(int i=0;i<T.size();i++){
    rem[i]=0;
  }
  for(int i=0;i<stage;i++){
    rem[as[i]]=1;
  }
  int match=0;
  for(int i=0;i<T.size();i++){
    if(match==P.size()){
      return true;
    }
    if(rem[i]){
      continue;
    }
    if(T[i]==P[match]){
      match++;
      continue;
    }
  }
  return (match==P.size());
}

int main(){
  std::cin>>T>>P;
  for(int i=0;i<T.size();i++){
    std::cin>>as[i];
    as[i]--;
  }
  int low=0,high=T.size();
  while(high-low>1){
    int mid=(low+high)/2;
    if(test(mid)){
      low=mid;
    }else{
      high=mid;
    }
  }
  std::cout<<low<<std::endl;
  return 0;
}