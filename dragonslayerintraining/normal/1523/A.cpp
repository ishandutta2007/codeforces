#include <iostream>
#include <algorithm>

void solve(){
  int N,M;
  std::string S;
  std::cin>>N>>M>>S;
  M=std::min(M,N);
  while(M--){
    std::string T=S;
    for(int i=0;i<N;i++){
      int cnt=0;
      if(i>0&&S[i-1]=='1'){
	cnt++;
      }
      if(i+1<N&&S[i+1]=='1'){
	cnt++;
      }
      if(cnt==1){
	T[i]='1';
      }
    }
    S=T;
  }
  std::cout<<S<<std::endl;
}


int main(){
  int T;
  std::cin>>T;
  while(T--){
    solve();
  }
  return 0;
}