#include <cstdio>
#include <cassert>
#include <vector>

const int MOD=31607;
const int INV10000=3973;

int ps[21][21];

int N;

//enumerate subset of columns
//row index, product of row elements not in subset for each row, product of column element in subset
int solve(int j,std::vector<int> row,int col){
  if(j==N){
    int res=col;
    for(int i=0;i<N;i++){
      res=res*(1-row[i])%MOD;
    }
    return res;
  }else{
    int new_col=col;
    for(int i=0;i<N;i++){
      new_col=new_col*ps[i][j]%MOD;
    }
    std::vector<int> new_row=row;
    for(int i=0;i<N;i++){
      new_row[i]=new_row[i]*ps[i][j]%MOD;
    }
    return (solve(j+1,new_row,col)-solve(j+1,row,new_col))%MOD;
  }
}


int main(){
  int orig[21][21];
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      int A;
      scanf("%d",&A);
      orig[i][j]=A*INV10000%MOD;
    }
  }
  int win[2][2];
  int diag[2][2];
  for(int d=0;d<2;d++){
    for(int f=0;f<2;f++){
      for(int i=0;i<N;i++){
	for(int j=0;j<N;j++){
	  ps[i][j]=orig[i][j];
	}
      }
      diag[d][f]=1;
      if(d){
	for(int i=0;i<N;i++){
	  diag[d][f]=(diag[d][f]*ps[i][i])%MOD;
	  ps[i][i]=1;
	}
      }
      if(f){
	for(int i=0;i<N;i++){
	  diag[d][f]=(diag[d][f]*ps[i][N-1-i])%MOD;
	  ps[i][N-1-i]=1;
	}
      }
      win[d][f]=(1-solve(0,std::vector<int>(N,1),1))*diag[d][f]%MOD;
    }
  }
  int ans=(win[0][0]+diag[1][0]+diag[0][1]
	   -win[0][1]-win[1][0]-diag[1][1]+win[1][1])%MOD;
  printf("%d\n",(ans+MOD)%MOD);
}