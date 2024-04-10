#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>

bool query(int R1,int C1,int R2,int C2){
  printf("? %d %d %d %d\n",R1,C1,R2,C2);
  fflush(stdout);
  char ans[5];
  scanf("%s",ans);
  if(!strcmp(ans,"YES")) return true;
  if(!strcmp(ans,"NO")) return false;
  exit(0);
}

std::string front,back;

int main(){
  int N;
  scanf("%d",&N);
  int r=1,c=1;
  while(r+c<N+1){
    if(query(r,c+1,N,N)){
      front+='R';
      c++;
    }else{
      front+='D';
      r++;
    }
  }
  r=N,c=N;
  while(r+c>N+1){
    if(query(1,1,r-1,c)){
      back+='D';
      r--;
    }else{
      back+='R';
      c--;
    }
  }
  std::reverse(back.begin(),back.end());
  printf("! %s%s\n",front.c_str(),back.c_str());
  return 0;
}