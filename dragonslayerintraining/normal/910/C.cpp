#include <iostream>
#include <algorithm>

int cnt[256];

bool leading[256];

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::string str;
    std::cin>>str;
    leading[str[0]]=true;
    int pow10=1;
    std::reverse(str.begin(),str.end());
    for(char c:str){
      cnt[c]+=pow10;
      pow10*=10;
    }
  }
  int* max=new int(0);
  for(int i='a';i<='j';i++){
    if(!leading[i]){
      if(cnt[i]>*max){
	max=&cnt[i];
      }
    }
  }
  *max=0;
  std::sort(cnt+'a',cnt+'k');
  std::reverse(cnt+'a',cnt+'k');
  int sum=0;
  for(int i=0;i<9;i++){
    sum+=cnt['a'+i]*(i+1);
  }
  std::cout<<sum<<std::endl;
  return 0;
}