#include <iostream>

int dp[501][2];

void solve(){
  std::string S,T;
  std::cin>>S>>T;
  for(int i=0;i<S.size();i++){
    dp[i][0]=dp[i][1]=(S[i]==T[0]);
  }
  for(int j=1;j<T.size();j++){
    char c=T[j];
    for(int i=0;i+1<S.size();i++){
      dp[i][1]=(S[i]==c&&(dp[i+1][0]||dp[i+1][1]));
    }
    dp[S.size()-1][1]=false;
    for(int i=S.size()-1;i>0;i--){
      dp[i][0]=(S[i]==c&&dp[i-1][0]);
    }
    dp[0][0]=false;
  }
  for(int i=0;i<S.size();i++){
    if(dp[i][0]||dp[i][1]){
      std::cout<<"YES"<<std::endl;
      return;
    }
  }
  std::cout<<"NO"<<std::endl;
}

int main(){
  int Q;
  std::cin>>Q;
  while(Q--){
    solve();
  }
}