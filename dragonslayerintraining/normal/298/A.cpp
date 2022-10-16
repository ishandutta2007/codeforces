#include <cstdio>
#include <algorithm>

int N;
char as[1005];

int R=0,L=1e9;

int main(){
  scanf("%d %s",&N,as);
  for(int i=0;i<N;i++){
    switch(as[i]){
    case 'R':R=std::max(R,i+1);break;
    case 'L':L=std::min(L,i+1);break;
    }
  }
  if(R>0){
    printf("%d %d\n",R,R+1);
  }else{
    printf("%d %d\n",L,L-1);
  }
  return 0;
}