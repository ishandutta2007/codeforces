#include <cstdio>
#include <deque>
#include <string>

char str[100005];

std::deque<int> O2;
int ones;

int main(){
  scanf("%s",str);
  for(int i=0;str[i];i++){
    if(str[i]=='0'||str[i]=='2'){
      O2.push_back(str[i]);
    }else{
      ones++;
    }
  }
  std::string ans;
  while(ones>0||O2.size()){
    if(O2.size()&&O2.front()=='0'){
      ans.push_back('0');
      O2.pop_front();
    }else if(ones){
      ans.push_back('1');
      ones--;
    }else if(O2.size()&&O2.front()=='2'){
      ans.push_back('2');
      O2.pop_front();
    }
  }
  printf("%s\n",ans.c_str());
  return 0;
}