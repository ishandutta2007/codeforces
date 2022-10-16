#include <iostream>
#include <cctype>

char neither(char a,char b){
  if((a!='A')&&(b!='A')){
    return 'A';
  }else if((a!='B')&&(b!='B')){
    return 'B';
  }else{
    return 'C';
  }
}

int main(){
  int N,K;
  std::cin>>N>>K;
  std::string str;
  std::cin>>str;
  if(K==2){
    int dp[2]={};
    for(int i=0;i<str.length();i++){
      dp[(i+str[i]-'A')%2]++;
    }
    int start=0;
    if(dp[0]<dp[1]){
      start=1;
    }else{
      start=0;
    }
    std::cout<<std::min(dp[0],dp[1])<<std::endl;
    for(int i=0;i<str.length();i++){
      std::cout<<char('A'+(i+start)%2);
    }
    std::cout<<std::endl;
  }else{
    int delta=0;
    for(int i=1;i<str.length();i++){
      if(str[i]==str[i-1]){
	//str[str.length()]=='\0', so it should work anyway
	str[i]=neither(str[i-1],str[i+1]);
	delta++;
      }
    }
    std::cout<<delta<<std::endl;
    std::cout<<str<<std::endl;
  }
  return 0;
}