#include <cstdio>

int as[200005];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  int inc=0;
  while(inc<N&&as[inc+1]>as[inc]){
    inc++;
  }
  int dec=N-1;
  while(dec>0&&as[dec-1]>as[dec]){
    dec--;
  }
  if(inc>=dec){
    puts("YES");
  }else{
    puts("NO");
  }
}