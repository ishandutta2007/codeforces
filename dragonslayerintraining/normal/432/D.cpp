#include <iostream>
#include <vector>
#include <algorithm>

std::string str;

int border[100001];
int counts[100001];


int main(){
  std::cin>>str;
  border[0]=-1;
  for(int i=0;i<str.length();i++){
    int k=border[i];
    while((k>=0)&&(str[k]!=str[i])){
      k=border[k];
    }
    border[i+1]=k+1;
  }
  for(int i=1;i<=str.length();i++){
    counts[border[i]]++;
  }
  for(int i=str.length();i>0;i--){
    counts[border[i]]+=counts[i];
  }
  std::vector<std::pair<int,int> > out;
  for(int k=str.length();k>0;k=border[k]){
    out.push_back(std::make_pair(k,counts[k]+1));
  }
  std::reverse(out.begin(),out.end());
  std::cout<<out.size()<<std::endl;
  for(int i=0;i<out.size();i++){
    std::cout<<out[i].first<<" "<<out[i].second<<std::endl;
  }
  return 0;
}