#include <iostream>
#include <iomanip>

int cnt[26][5000][26];
int amount[26];
int opt[26];

int main(){
  std::string S;
  std::cin>>S;
  for(int i=0;i<S.length();i++){
    for(int j=0;j<S.length();j++){
      cnt[S[i]-'a'][j][S[(i+j)%S.length()]-'a']++;
    }
    amount[S[i]-'a']++;
  }
  for(int s=0;s<26;s++){
    for(int i=0;i<S.length();i++){
      int good=0;
      for(int c=0;c<26;c++){
	good+=(cnt[s][i][c]==1);
      }
      opt[s]=std::max(opt[s],good);
    }
  }
  double sum=0;
  for(int i=0;i<S.length();i++){
    sum+=double(opt[S[i]-'a'])/amount[S[i]-'a'];
  }
  std::cout<<std::fixed<<std::setprecision(10)<<double(sum)/S.length()<<std::endl;
  return 0;
}