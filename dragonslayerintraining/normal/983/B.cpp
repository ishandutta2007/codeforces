#include <cstdio>
#include <algorithm>

int as[5000];

int ans[5001][5001];
int msb[5001];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  int k=1;
  for(int i=1;i<=5000;i++){
    if((k<<1)<=i) k<<=1;
    msb[i]=k;
  }
  for(int l=0;l+1<=N;l++){
    ans[l][l+1]=as[l];
  }
  for(int d=2;d<=N;d++){
    for(int l=0;l+d<=N;l++){
      int r=l+d;
      int k=d-msb[d-1];
      ans[l][r]=ans[l][l+k]^ans[r-k][r];
    }
  }
  for(int d=2;d<=N;d++){
    for(int l=0;l+d<=N;l++){
      int r=l+d;
      ans[l][r]=std::max(ans[l][r],std::max(ans[l+1][r],ans[l][r-1]));
    }
  }
  int Q;
  scanf("%d",&Q);
  for(int i=0;i<Q;i++){
    int L,R;
    scanf("%d %d",&L,&R);
    L--;
    printf("%d\n",ans[L][R]);
  }
  return 0;
}