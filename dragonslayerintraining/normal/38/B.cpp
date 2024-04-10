#include <iostream>

bool board[8][8];

void place(int x,int y){
  if((x>=0)&&(x<8)&&(y>=0)&&(y<8)){
    board[x][y]=true;
  }
}

void placeknight(int x,int y){
  place(x,y);
  place(x+2,y+1);
  place(x+2,y-1);
  place(x-2,y+1);
  place(x-2,y-1);
  place(x+1,y+2);
  place(x+1,y-2);
  place(x-1,y+2);
  place(x-1,y-2);
}
void placerook(int x,int y){
  for(int i=0;i<8;i++){
    place(x,i);
    place(i,y);
  }
}


int main(){
  std::string a,b;
  std::cin>>a>>b;
  placerook(a[0]-'a',a[1]-'1');
  placeknight(a[0]-'a',a[1]-'1');
  placeknight(b[0]-'a',b[1]-'1');
  int cnt=0;
  for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
      if(!board[i][j]){
	cnt++;
      }
    }
  }
  std::cout<<cnt<<std::endl;
  
  return 0;
}