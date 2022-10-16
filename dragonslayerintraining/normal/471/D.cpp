#include <cstdio>

int N,W;

int haystack[200000];
int needle[200000];

int border[200000];

int main(){
  scanf("%d %d",&N,&W);
  if(W==1){
    printf("%d\n",N);
    return 0;
  }
  for(int i=0;i<N;i++){
    scanf("%d",&haystack[i]);
  }
  for(int i=0;i<W;i++){
    scanf("%d",&needle[i]);
  }
  for(int i=0;i<N-1;i++){
    haystack[i]=haystack[i+1]-haystack[i];
  }
  for(int i=0;i<W-1;i++){
    needle[i]=needle[i+1]-needle[i];
  }
  N--,W--;
  border[0]=-1;
  for(int i=0;i<W;i++){
    int k=border[i];
    while((k>=0)&&(needle[i]!=needle[k])){
      k=border[k];
    }
    border[i+1]=k+1;
  }
  int cnt=0;
  int m=0;
  for(int i=0;i<N;i++){
    while((m>=0)&&((m>=W)||(needle[m]!=haystack[i]))){
      m=border[m];
    }
    if(++m==W){
      cnt++;
    }
  }
  printf("%d\n",cnt);
  return 0;
}