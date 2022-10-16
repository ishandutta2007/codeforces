#include <cstdio>
#include <vector>

void move(int b,std::pair<int,int> p){
  printf("%d %d %d\n",b,p.first+1,p.second+1);
  fflush(stdout);
}

int main(){
  int N;
  scanf("%d",&N);
  std::vector<std::pair<int,int> > grid1,grid2;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if((i+j)%2==0){
	grid1.push_back({i,j});
      }else{
	grid2.push_back({i,j});
      }
    }
  }
  int index1=0,index2=0;
  while(index1<grid1.size()&&index2<grid2.size()){
    int A;
    scanf("%d",&A);
    if(A!=1){
      move(1,grid1[index1++]);
    }else{
      move(2,grid2[index2++]);
    }
  }
  while(index1<grid1.size()){
    int A;
    scanf("%d",&A);
    if(A!=1){
      move(1,grid1[index1++]);
    }else{
      move(3,grid1[index1++]);
    }
  }
  while(index2<grid2.size()){
    int A;
    scanf("%d",&A);
    if(A!=2){
      move(2,grid2[index2++]);
    }else{
      move(3,grid2[index2++]);
    }
  }
}