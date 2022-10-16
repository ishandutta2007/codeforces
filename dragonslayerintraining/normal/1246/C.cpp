#include <cstdio>

const int MOD=1e9+7;

char grid[2005][2005];
int rocksx[2005][2005];
int rocksy[2005][2005];

int dpx[2005][2005];//number of paths starting with +x or stop
int dpy[2005][2005];//number of paths starting with +y or stop
int dpxsuf[2005][2005];
int dpysuf[2005][2005];

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=1;i<=N;i++){
    scanf("%s",grid[i]+1);
  }
  if(N==1&&M==1){
    printf("1\n");
    return 0;
  }
  for(int i=1;i<=N;i++){
    for(int j=1;j<=M;j++){
      rocksx[i][j]=rocksx[i-1][j]+(grid[i][j]=='R');
      rocksy[i][j]=rocksy[i][j-1]+(grid[i][j]=='R');
    }
  }
  for(int i=N;i>=1;i--){
    for(int j=M;j>=1;j--){
      if((i==N)&&(j==M)){
	dpx[i][j]=1;
	dpy[i][j]=1;
      }else{
	int farx=N-(rocksx[N][j]-rocksx[i][j]);
	dpx[i][j]=(dpxsuf[i+1][j]-dpxsuf[farx+1][j]+MOD)%MOD;
	int fary=M-(rocksy[i][M]-rocksy[i][j]);
	dpy[i][j]=(dpysuf[i][j+1]-dpysuf[i][fary+1]+MOD)%MOD;
      }
      dpxsuf[i][j]=(dpxsuf[i+1][j]+dpy[i][j])%MOD;
      dpysuf[i][j]=(dpysuf[i][j+1]+dpx[i][j])%MOD;
    }
  }
  /*
  printf("Moves Down:\n");
  for(int i=1;i<=N;i++){
    for(int j=1;j<=M;j++){
      printf("%d",N-i-(rocksx[N][j]-rocksx[i][j]));
    }
    printf("\n");
  }
  printf("\n");
  printf("Moves Right:\n");
  for(int i=1;i<=N;i++){
    for(int j=1;j<=M;j++){
      printf("%d",M-j-(rocksy[i][M]-rocksy[i][j]));
    }
    printf("\n");
  }
  printf("Down:\n");
  for(int i=1;i<=N;i++){
    for(int j=1;j<=M;j++){
      printf("%d",dpx[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  printf("Right:\n");
  for(int i=1;i<=N;i++){
    for(int j=1;j<=M;j++){
      printf("%d",dpy[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  */
  printf("%d\n",(dpx[1][1]+dpy[1][1])%MOD);
}