#include <cstdio>

char grid[4][4];

int main(){
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      char c;
      for(c=getchar();(c!='#')&&(c!='.');c=getchar());
      if(c=='#'){
	grid[i][j]=0;
      }else{
	grid[i][j]=1;
      }
    }
  }
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      if(grid[i][j]+grid[i][j+1]+grid[i+1][j]+grid[i+1][j+1]!=2){
	printf("YES\n");
	return 0;
      }
    }
  }
  printf("NO\n");
  return 0;
}