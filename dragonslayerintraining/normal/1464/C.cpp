#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>

int N;
long long T;
char str[100005];

int main(){
  scanf("%d %lld",&N,&T);
  scanf("%s",str);
  std::vector<int> v;
  for(int i=0;i<N-1;i++){
    T+=(1<<(str[i]-'a'));
  }
  T-=(1<<(str[N-1]-'a'));
  
  for(int i=0;i<N-2;i++){
    v.push_back(str[i]-'a'+1);
  }
  std::sort(v.begin(),v.end(),std::greater<int>());
  for(int x:v){
    if(T>=(1<<x)){
      T-=(1<<x);
    }
  }
  if(T==0){
    printf("Yes\n");
  }else{
    printf("No\n");
  }
}