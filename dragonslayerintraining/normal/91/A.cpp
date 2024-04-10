#include <iostream>

int next[26][10000];
int sweeper[26];

int main(){
  std::string str1,str2;
  std::cin>>str1>>str2;
  for(int l=0;l<26;l++){
    sweeper[l]=str1.length();
  }
  for(int i=str1.length()-1;i>=0;i--){
    sweeper[str1[i]-'a']=i;
    for(int l=0;l<26;l++){
      next[l][i]=sweeper[l];
    }
  }
  int j=0;
  int cnt;
  for(cnt=0;j<str2.size();cnt++){
    int i=0;
    while((i<str1.size())&&(j<str2.size())){
      int i2=next[str2[j]-'a'][i];
      if(i2==str1.size()){
	if(i==0){
	  std::cout<<-1<<std::endl;
	  return 0;
	}
	break;
      }
      i=i2+1;
      j++;
    }
  }
  std::cout<<cnt<<std::endl;
  return 0;
}