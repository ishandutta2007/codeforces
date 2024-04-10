#include <iostream>

int dist[26][26];

int main(){
  std::string s1,s2;
  std::cin>>s1>>s2;
  if(s1.length()!=s2.length()){
    std::cout<<-1<<std::endl;
    return 0;
  }
  int N;
  std::cin>>N;
  for(int i=0;i<26;i++){
    for(int j=0;j<26;j++){
      dist[i][j]=(i==j)?0:1e9;
    }
  }
  for(int i=0;i<N;i++){
    std::string a,b;
    int d;
    std::cin>>a>>b>>d;
    std::cerr<<"a: "<<a<<"\tb: "<<b<<std::endl;
    int& x=dist[a[0]-'a'][b[0]-'a'];
    x=std::min(x,d);
  }
  for(int k=0;k<26;k++){
    for(int i=0;i<26;i++){
      for(int j=0;j<26;j++){
	dist[i][j]=std::min(dist[i][j],dist[i][k]+dist[k][j]);
      }
    }
  }
  int cost=0;
  std::string str;
  for(int i=0;i<s1.length();i++){
    char a=s1[i]-'a',b=s2[i]-'a';
    int mindist=1e9;
    str.push_back('\0');
    for(int k=0;k<26;k++){
      if(mindist>dist[a][k]+dist[b][k]){
	mindist=dist[a][k]+dist[b][k];
	str[i]=k+'a';
      }
    }
    if(mindist>=1e9){
      std::cout<<-1<<std::endl;
      return 0;
    }
    cost+=mindist;
  }
  std::cout<<cost<<std::endl;
  std::cout<<str<<std::endl;
  return 0;
}