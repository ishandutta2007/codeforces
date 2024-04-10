#include <cstdio>
#include <algorithm>

int N;
char grid[2005][2005];

int layer(int i,int j){
  if(i>=N/2) i=N-1-i;
  if(j>=N/2) j=N-1-j;
  return std::min(i,j)%2;
}

int ring(int i,int j){
  if((i+j)%2==0){
    int l=(i+j)/2;
    if(l>=N/2){
      l=N-1-l;
    }
    return l;
  }else{
    return std::labs(i-j)/2;
  }
}

int basis[1000];

int main(){
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%s",grid[i]);
  }
  if(N%2){
    printf("NONE\n");
    return 0;
  }
  std::fill(basis,basis+N/2,-1);
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(grid[i][j]!='.'){
	int v=(grid[i][j]=='G')^layer(i,j);
	int l=ring(i,j);
	if(basis[l]!=-1&&basis[l]!=v){
	  printf("NONE\n");
	  return 0;
	}else{
	  basis[l]=v;
	}
      }
    }
  }
  if(std::count(basis,basis+N/2,-1)){
    printf("MULTIPLE\n");
  }else{
    printf("UNIQUE\n");
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
	printf("%c",(layer(i,j)^basis[ring(i,j)])?'G':'S');
      }
      printf("\n");
    }
  }
}