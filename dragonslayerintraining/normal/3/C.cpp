#include <cstdio>

char board[3][3];

int main(){
  scanf("%s %s %s",board[0],board[1],board[2]);

  int xs=0,os=0;

  for(int y=0;y<3;y++){
    for(int x=0;x<3;x++){
      xs+=(board[x][y]=='X');
      os+=(board[x][y]=='0');	
    }
  }
  if(((xs-os)<0)||((xs-os)>1)){
    printf("illegal\n");
    return 0;
  }
  int xvs=0,xhs=0,xds=0;
  int ovs=0,ohs=0,ods=0;
  for(int y=0;y<3;y++){
    if((board[0][y]==board[1][y])&&(board[0][y]==board[2][y])){
      if(board[0][y]=='X'){
	xhs++;
      }else if(board[0][y]=='0'){
	ohs++;
      }
    }
  }
  for(int x=0;x<3;x++){
    if((board[x][0]==board[x][1])&&(board[x][0]==board[x][2])){
      if(board[x][0]=='X'){
	xvs++;
      }else if(board[x][0]=='0'){
	ovs++;
      }
    }
  }
  if((board[0][0]==board[1][1])&&(board[0][0]==board[2][2])){
    if(board[0][0]=='X'){
      xds++;
    }else if(board[0][0]=='0'){
      ods++;
    }
  }
  if((board[2][0]==board[1][1])&&(board[2][0]==board[0][2])){
    if(board[2][0]=='X'){
      xds++;
    }else if(board[2][0]=='0'){
      ods++;
    }
  }

  if((xhs>1)||(xvs>1)){
    printf("illegal\n");
    return 0;
  }
  if((ohs>1)||(ovs>1)){
    printf("illegal\n");
    return 0;
  }
  bool xwon=(xhs+xvs+xds>0);
  bool owon=(ohs+ovs+ods>0);
  if(xwon&&owon){
    printf("illegal\n");
    return 0;
  }else if(xwon){
    if(xs-os!=1){
      printf("illegal\n");
    }else{
      printf("the first player won\n");
    }
    return 0;
  }else if(owon){
    if(xs-os!=0){
      printf("illegal\n");
    }else{
      printf("the second player won\n");
    }
    return 0;
  }else{
    if(xs+os==9){
      printf("draw\n");
      return 0;
    }else if(xs-os==0){
      printf("first\n");
      return 0;
    }else if (xs-os==1){
      printf("second\n");
      return 0;
    }
  }
  return 0;
}