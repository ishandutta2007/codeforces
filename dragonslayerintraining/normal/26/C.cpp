#include <iostream>

char grid[100][100];
int A,B,C;

void lay(int x,int y,int width,int height){
  char c='a'+(x%4)*4+(y%4);
  for(int i=0;i<width;i++){
    for(int j=0;j<height;j++){
      grid[x+i][y+j]=c;
    }
  }
  if((width==1)&&(height==2)){
    A--;
  }else if((width==2)&&(height==1)){
    B--;
  }else{
    C--;
  }
}

bool tile(int N,int M){
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(C>0){
	lay(i*2,j*2,2,2);
      }else if(B>1){
	lay(i*2,j*2,2,1);
	lay(i*2,j*2+1,2,1);
      }else if(A>1){
	lay(i*2,j*2,1,2);
	lay(i*2+1,j*2,1,2);
      }else{
	return false;
      }
    }
  }
  return true;
}

int main(){
  int N,M;
  std::cin>>N>>M>>A>>B>>C;
  if((N*M)%2==1){
    std::cout<<"IMPOSSIBLE"<<std::endl;
    return 0;
  }
  if(N%2==1){
    for(int i=0;i<M;i+=2){
      lay(N-1,i,1,2);
    }
  }
  else if(M%2==1){
    for(int i=0;i<N;i+=2){
      lay(i,M-1,2,1);
    }
  }
  if((A<0)||(B<0)||(C<0)){
    std::cout<<"IMPOSSIBLE"<<std::endl;
    return 0;
  }
  if(!tile(N/2,M/2)){
    std::cout<<"IMPOSSIBLE"<<std::endl;
    return 0;
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      std::cout<<grid[i][j];
    }
    std::cout<<std::endl;
  }
  return 0;
}