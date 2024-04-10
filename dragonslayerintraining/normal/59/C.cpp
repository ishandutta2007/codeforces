#include <iostream>
#include <set>

int main(){
  int K;
  std::cin>>K;
  std::string str;
  std::cin>>str;
  for(int i=0;i<str.length();i++){
    if(str[i]>='a'+K){
      std::cout<<"IMPOSSIBLE"<<std::endl;
      return 0;
    }
  }
  std::string left;
  left.resize((str.length()+1)/2);
  for(int i=0;i<left.length();i++){
    if(str[i]=='?'){
      left[i]=str[str.length()-1-i];
    }else if(str[str.length()-1-i]=='?'){
      left[i]=str[i];
    }else if(str[i]==str[str.length()-1-i]){
      left[i]=str[i];
    }else{
      std::cout<<"IMPOSSIBLE"<<std::endl;
      return 0;
    }
  }
  std::set<char> rem;
  for(int i=0;i<K;i++){
    rem.insert('a'+i);
  }
  for(int i=0;i<left.size();i++){
    rem.erase(left[i]);
  }
  for(int i=left.size()-1;i>=0;i--){
    if(left[i]=='?'){
      if(rem.empty()){
	left[i]='a';
      }else{
	left[i]=*rem.rbegin();
	rem.erase(--rem.end());
      }
    }
  }
  if(!rem.empty()){
    std::cout<<"IMPOSSIBLE"<<std::endl;
    return 0;
  }
  for(int i=0;i<str.length();i++){
    std::cout<<left[(i*2>=str.length())?(str.length()-1-i):i];
  }
  std::cout<<std::endl;
  return 0;
}