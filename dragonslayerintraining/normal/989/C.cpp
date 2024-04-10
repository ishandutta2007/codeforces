#include <cstdio>
#include <algorithm>

char grid[55][55];

int cnts[4];

void drop(int y,char c){
  for(int i=y;i<y+10;i+=2){
    for(int j=0;j<50;j+=2){
      if(cnts[c-'A']>0){
	grid[i][j]=c;
	cnts[c-'A']--;
      }
    }
  }
}

int main(){
  for(int i=0;i<4;i++){
    scanf("%d",&cnts[i]);
  }
  printf("50 50\n");
  for(int i=0;i<25;i++){
    std::fill(grid[i],grid[i]+50,'A');
  }
  for(int i=25;i<50;i++){
    std::fill(grid[i],grid[i]+50,'B');
  }
  cnts[0]--;
  cnts[1]--;
  drop(0,'B');
  drop(10,'C');
  drop(30,'A');
  drop(40,'D');
  for(int i=0;i<50;i++){
    printf("%s\n",grid[i]);
  }
  return 0;
}