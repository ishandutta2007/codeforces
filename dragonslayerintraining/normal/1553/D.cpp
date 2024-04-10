#include <iostream>

void solve(){
  std::string S,T;
  std::cin>>S>>T;
  if((S.size()+T.size())%2==1){
    S.erase(S.begin());
  }
  int i=0;
  for(char c:T){
    while(i<S.size()&&S[i]!=c){
      i+=2;
    }
    if(i>=S.size()){
      std::cout<<"NO"<<std::endl;
      return;
    }
    i++;
  }
  std::cout<<"YES"<<std::endl;
}

int main(){
  int Q;
  std::cin>>Q;
  while(Q--){
    solve();
  }
}