#include <cstdio>
#include <cstring>
#include <algorithm>

char str[200005];
int N;

bool check(int thres){
  int ones=std::count(str,str+N,'1');
  int zeros=0;
  int l=0;
  for(int r=0;r<=N;r++){
    while(zeros>thres){
      ones+=(str[l]=='1');
      zeros-=(str[l]=='0');
      l++;
    }
    if(ones<=thres){
      return true;
    }
    ones-=(str[r]=='1');
    zeros+=(str[r]=='0');
  }
  return false;
}

void solve(){
  scanf("%s",str);
  N=strlen(str);
  int low=-1,high=N;
  while(high-low>1){
    int mid=(low+high)/2;
    if(check(mid)){
      high=mid;
    }else{
      low=mid;
    }
  }
  printf("%d\n",high);
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}