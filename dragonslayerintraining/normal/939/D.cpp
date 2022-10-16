#include <iostream>
#include <vector>
#include <algorithm>

std::string s1,s2;

int uf[26];

int find(int a){
  return (a==uf[a])?a:(uf[a]=find(uf[a]));
}

int unite(int a,int b){
  uf[find(a)]=find(b);
}

int main(){
  int N;
  std::cin>>N;
  std::cin>>s1>>s2;
  std::iota(uf,uf+26,0);
  std::vector<std::pair<char,char> > ans;
  for(int i=0;i<N;i++){
    if(find(s1[i]-'a')!=find(s2[i]-'a')){
      ans.emplace_back(s1[i],s2[i]);
      unite(s1[i]-'a',s2[i]-'a');
    }
  }
  std::cout<<ans.size()<<std::endl;
  for(auto pair:ans){
    std::cout<<pair.first<<" "<<pair.second<<std::endl;
  }
  return 0;
}