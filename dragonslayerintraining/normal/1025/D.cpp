#include <cstdio>

int as[800];

bool dpl[800][800];
bool dpr[800][800];

bool edge[800][800];

int gcd(int a,int b){
  return b?gcd(b,a%b):a;
}

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(gcd(as[i],as[j])>1){
	edge[i][j]=true;
      }
    }
  }
  for(int i=0;i<N;i++){
    dpl[i][i]=true;
    dpr[i][i]=true;
  }
  for(int len=0;len<N;len++){
    for(int l=0;l+len<N;l++){
      int r=l+len;
      for(int m=l;m<=r;m++){
	if(dpl[l][m]&&dpr[m][r]){
	  if(r<N-1&&edge[m][r+1]){
	    dpl[l][r+1]=true;
	  }
	  if(l>0&&edge[l-1][m]){
	    dpr[l-1][r]=true;
	  }
	}
      }
    }
  }
  for(int i=0;i<N;i++){
    if(dpl[0][i]&&dpr[i][N-1]){
      printf("Yes\n");
      return 0;
    }
  }
  printf("No\n");
  return 0;
}