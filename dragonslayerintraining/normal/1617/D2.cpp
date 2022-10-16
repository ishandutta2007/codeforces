#include <cstdio>
#include <cstdlib>
#include <algorithm>

int query(int a,int b,int c){
  printf("? %d %d %d\n",a+1,b+1,c+1);
  fflush(stdout);
  int res;
  scanf("%d",&res);
  if(res==-1){
    exit(0);
  }
  return res;
}

int val[10004];
int known[2];

void identify(int i){
  val[i]=query(known[0],known[1],i);
}

void solve(){
  int N;
  scanf("%d",&N);
  int flag=query(0,1,2);
  int i=3;
  while(query(i,i+1,i+2)==flag){
    i+=3;
  }
  int j=i-1;
  while(j>i-3&&query(j,j+1,j+2)!=flag){
    j--;
  }
  val[j]=flag;
  val[j+3]=!flag;
  known[flag]=j;
  known[!flag]=j+3;
  for(int k=i-3;k<N;k++){
    if(k!=j&&k!=j+3){
      identify(k);
    }
  }
  for(int k=0;k<i-3;k+=3){
    if(query(k,k+1,known[!flag])==flag){
      val[k]=flag;
      val[k+1]=flag;
      identify(k+2);
    }else{
      identify(k);
      val[k+1]=!val[k];
      val[k+2]=flag;
    }
  }
  printf("! %d",(int)std::count(val,val+N,0));
  for(int i=0;i<N;i++){
    if(val[i]==0){
      printf(" %d",i+1);
    }
  }
  printf("\n");
  fflush(stdout);
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}