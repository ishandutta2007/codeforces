#include <iostream>
#include <algorithm>

void solve(){
  int N;
  std::string S,T;
  std::cin>>N;
  std::cin>>S;
  T=S;
  std::sort(T.begin(),T.end());
  int cnt=0;
  for(int i=0;i<S.length();i++){
    if(S[i]!=T[i]){
      cnt++;
    }
  }
  printf("%d\n",cnt);
}

int main(){
  int T;
  std::cin>>T;
  while(T--){
    solve();
  }
}