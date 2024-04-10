#include <iostream>
#include <algorithm>

int dp[100001][3];

int main(){
  std::string str;
  std::cin>>str;
  for(int i=0;i<=str.length();i++){
    for(int r=0;r<3;r++){
      dp[i][r]=1e9;
    }
  }
  for(int i=0;i<str.length();i++){
    for(int r=0;r<3;r++){
      int r2=(r*10+str[i]-'0')%3;
      dp[i+1][r2]=std::min(dp[i+1][r2],dp[i][r]);
      dp[i+1][r]=std::min(dp[i+1][r],dp[i][r]+1);
    }
    if(str[i]!='0'){
      int rh=(str[i]-'0')%3;
      dp[i+1][rh]=std::min(dp[i+1][rh],i);
    }
  }
  int ans=dp[str.length()][0];
  if(ans>=str.length()){
    for(int i=0;i<str.length();i++){
      if(str[i]=='0'){
	std::cout<<"0"<<std::endl;
	return 0;
      }
    }
    std::cout<<"-1"<<std::endl;
    return 0;
  }else{
    std::string ac;
    int r2=0;
    for(int i=str.length()-1;i>=0;i--){
      if(str[i]!='0'&&(str[i]-'0')%3==r2&&dp[i+1][(str[i]-'0')%3]==i){
	ac.push_back(str[i]);
	break;
      }
      for(int r=0;r<3;r++){
	if((r*10+str[i]-'0')%3==r2&&dp[i+1][r2]==dp[i][r]){
	  ac.push_back(str[i]);
	  r2=r;
	  break;
	}
	if(r==r2&&dp[i+1][r]==dp[i][r]+1){
	  r2=r;
	  break;
	}
      }
    }
    std::reverse(ac.begin(),ac.end());
    std::cout<<ac<<std::endl;
  }
  return 0;
}