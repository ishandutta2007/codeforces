#include <cstdio>
#include <cmath>

int adj[1000][1000];

int main(){
  int N,A,B;
  scanf("%d %d %d",&N,&A,&B);
  if((A==1)&&(B==1)){
    if(N==2||N==3){
      printf("NO\n");
      return 0;
    }
    printf("YES\n");
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
	printf("%d",std::abs(i-j)==1);
      }
      printf("\n");
    }
  }else if(B==1){
    for(int i=N;i>A;i--){
      adj[0][i-1]=adj[i-1][0]=1;
    }
    printf("YES\n");
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
	printf("%d",adj[i][j]);
      }
      printf("\n");
    }
  }else if(A==1){
    for(int i=N;i>B;i--){
      adj[0][i-1]=adj[i-1][0]=1;
    }
    printf("YES\n");
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
	printf("%d",(i!=j)&&!adj[i][j]);
      }
      printf("\n");
    }
  }else{
    printf("NO\n");
  }
  return 0;
}