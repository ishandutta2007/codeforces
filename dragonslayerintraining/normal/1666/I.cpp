#include <cstdio>

int scan(int r,int c){
  printf("SCAN %d %d\n",r+1,c+1);
  fflush(stdout);
  int D;
  scanf("%d",&D);
  return D;
}

bool dig(int r,int c){
  printf("DIG %d %d\n",r+1,c+1);
  fflush(stdout);
  int F;
  scanf("%d",&F);
  return F;
}

void solve(){
  int N,M;
  scanf("%d %d",&N,&M);
  int A=scan(0,0);
  int B=scan(N-1,0);
  int csum=(A+B)/2-(N-1);
  int rsum=(A-B)/2+(N-1);
  int rdiff=scan(rsum/2,0)-csum;
  int cdiff=scan(0,csum/2)-rsum;
  int r1=(rsum+rdiff)/2,r2=(rsum-rdiff)/2;
  int c1=(csum+cdiff)/2,c2=(csum-cdiff)/2;
  if(dig(r1,c1)){
    dig(r2,c2);
  }else{
    dig(r1,c2);
    dig(r2,c1);
  }
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}