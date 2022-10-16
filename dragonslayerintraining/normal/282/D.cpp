#include <iostream>

int as[3];
int N;

int v[300][300][300];

void solve(){
  for(int i=0;i<=as[0];i++){
    for(int j=0;j<=as[1];j++){
      for(int k=0;k<=as[2];k++){
	if(i>0){
	  v[i][j][k]|=(v[i-1][j][k]&8);
	}
	if(j>0){
	  v[i][j][k]|=(v[i][j-1][k]&4);
	}
	if(k>0){
	  v[i][j][k]|=(v[i][j][k-1]&2);
	}
	switch(N){
	case 1:
	  if(i>0){
	    v[i][j][k]|=(v[i-1][j][k]&1);
	  }
	  break;
	case 2:
	  if((i>0)&&(j>0)){
	    v[i][j][k]|=(v[i-1][j-1][k]&1);
	  }
	  break;
	case 3:
	  if((i>0)&&(j>0)&&(k>0)){
	    v[i][j][k]|=(v[i-1][j-1][k-1]&1);
	  }
	  break;
	}
	if(v[i][j][k]==0){
	  v[i][j][k]=0x1f;
	}
      }
    }
  }
}

int main(){
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>as[i];
  }
  solve();
  if(v[as[0]][as[1]][as[2]]&0x10){
    std::cout<<"BitAryo"<<std::endl;
  }else{
    std::cout<<"BitLGM"<<std::endl;
  }
  return 0;
}