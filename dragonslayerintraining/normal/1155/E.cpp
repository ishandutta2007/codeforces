#include <cstdio>

const int MOD=1e6+3;

int vs[1000005][12];

int query(int x){
  printf("? %d\n",x);
  fflush(stdout);
  int res;
  scanf("%d",&res);
  return res;
}

int main(){
  for(int i=0;i<=10;i++){
    vs[i][0]=query(i);
  }
  for(int k=1;k<=10;k++){
    for(int i=0;i<=10-k;i++){
      vs[i][k]=(vs[i+1][k-1]+MOD-vs[i][k-1])%MOD;
    }
  }
  for(int k=11;k>0;k--){
    for(int i=0;i<1000003;i++){
      vs[i+1][k-1]=(vs[i][k]+vs[i][k-1])%MOD;
    }
  }
  for(int i=0;i<1000003;i++){
    if(vs[i][0]==0){
      printf("! %d\n",i);
      return 0;
    }
  }
  printf("! -1\n");
  return 0; 
}