#include <cstdio>
#include <vector>

char str[1000005];

std::vector<std::pair<char,int> > read_string(){
  scanf("%s",str);
  std::vector<std::pair<char,int> > res;
  for(int i=0;str[i];i++){
    if(i==0||str[i]!=str[i-1]){
      res.push_back({str[i],1});
    }else{
      res.back().second++;
    }
  }
  return res;
}

bool solve(){
  std::vector<std::pair<char,int> > first=read_string();
  std::vector<std::pair<char,int> > second=read_string();
  if(first.size()!=second.size()) return false;
  for(int i=0;i<first.size();i++){
    if(first[i].first!=second[i].first) return false;
    if(first[i].second>second[i].second) return false;
  }
  return true;
}

int main(){
  int N;
  scanf("%d",&N);
  while(N--){
    if(solve()){
      printf("YES\n");
    }else{
      printf("NO\n");
    }
  }
  return 0;
}