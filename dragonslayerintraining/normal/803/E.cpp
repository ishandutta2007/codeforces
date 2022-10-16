#include <cstdio>
#include <map>
#include <cassert>

char str[100005];

std::map<char,int> inc,dec;

int low[100005];
int high[100005];

int main(){
  inc['W']=1,dec['W']=1;
  inc['D']=0,dec['D']=0;
  inc['L']=-1,dec['L']=-1;
  inc['?']=1,dec['?']=-1;
  int N,K;
  scanf("%d %d",&N,&K);
  scanf("%s",str);
  for(int i=0;i<N;i++){
    int limit=(i==N-1)?K:(K-1);
    low[i+1]=std::max(-limit,low[i]+dec[str[i]]);
    high[i+1]=std::min(limit,high[i]+inc[str[i]]);
    //printf("low[%d]=%d\n",i+1,low[i+1]);
    //printf("high[%d]=%d\n",i+1,high[i+1]);
    if(low[i+1]>high[i+1]){
      printf("NO\n");
      return 0;
    }
  }
  if(low[N]==-K){
    high[N]=-K;
  }else{
    low[N]=K;
  }
  for(int i=N-1;i>=0;i--){
    low[i]=std::max(low[i],low[i+1]-inc[str[i]]);
    high[i]=std::min(high[i],high[i+1]-dec[str[i]]);
    //printf("low[%d]=%d\n",i+1,low[i+1]);
    //printf("high[%d]=%d\n",i+1,high[i+1]);
  }
  //printf("low[%d]=%d\n",0,low[0]);
  //printf("high[%d]=%d\n",0,high[0]);
  if(low[0]!=0||high[0]!=0){
    printf("NO\n");
    return 0;
  }
  for(int i=0;i<N;i++){
    switch(low[i+1]-low[i]){
    case -1:putchar('L');break;
    case 0:putchar('D');break;
    case 1:putchar('W');break;
    default:assert(0);break;
    }
  }
  printf("\n");
  return 0;
}