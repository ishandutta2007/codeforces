#include <cstdio>
#include <algorithm>
#include <cstdlib>

char A[11][11];
char B[11][11];
int N;

template<class T>
void check(T func){
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(!func(i,j)) return;
    }
  }
  printf("Yes\n");
  exit(0);
}

int main(){
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%s",A[i]);
  }
  for(int i=0;i<N;i++){
    scanf("%s",B[i]);
  }
  for(int t=0;t<2;t++){
    check([](int i,int j){return A[i][j]==B[i][j];});
    check([](int i,int j){return A[i][j]==B[N-1-j][i];});
    check([](int i,int j){return A[i][j]==B[N-1-i][N-1-j];});
    check([](int i,int j){return A[i][j]==B[j][N-1-i];});
    
    for(int i=0;i<N;i++){
      for(int j=0;j<i;j++){
	std::swap(A[i][j],A[j][i]);
      }
    }
  }
  printf("No\n");
  return 0;
}