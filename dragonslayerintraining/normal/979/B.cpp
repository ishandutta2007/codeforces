#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>

char str[100005];
int N;

int read(){
  std::map<char,int> cnt;
  scanf("%s",str);
  int len=strlen(str);
  for(int i=0;str[i];i++){
    cnt[str[i]]++;
  }
  if(cnt.size()==1){
    return (N==1)?(len-1):len;
  }
  int max=0;
  for(auto pair:cnt){
    max=std::max<int>(max,pair.second);
  }
  return std::min<int>(max+N,len);
}

char cat[3][20]={"Kuro","Shiro","Katie"};

int main(){
  scanf("%d",&N);
  int as[3];
  as[0]=read();
  as[1]=read();
  as[2]=read();
  int* max=std::max_element(as,as+3);
  if(std::count(as,as+3,*max)!=1){
    printf("Draw\n");
  }else{
    printf("%s\n",cat[max-as]);
  }
  return 0;
}