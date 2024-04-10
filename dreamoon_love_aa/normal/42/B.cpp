#include<stdio.h>
char board[8][8];
struct data{
    int x,y;
    void scan(){
        char s[8];
        scanf("%s",s);
        x=s[0]-'a';
        y=s[1]-'1';
    }
}a[4];
bool Out(int x,int y){return x<0||y<0||x>=8||y>=8;}
bool Check(int x,int y){
    int i,j;
    for(i=-1;i<2;i++)
        for(j=-1;j<2;j++){
            if(Out(x+i,y+j))continue;
            if(board[x+i][y+j]=='k')return 1;
        }
    for(i=1;x+i<8;i++){
        if(board[x+i][y]=='r')return 1;
        if(board[x+i][y])break;
    }
    for(i=1;x-i>=0;i++){
        if(board[x-i][y]=='r')return 1;
        if(board[x-i][y])break;
    }
    for(i=1;y+i<8;i++){
        if(board[x][y+i]=='r')return 1;
        if(board[x][y+i])break;
    }
    for(i=1;y-i>=0;i++){
        if(board[x][y-i]=='r')return 1;
        if(board[x][y-i])break;
    }
    return 0;
}
main(){
    int i,j;
    for(i=0;i<4;i++)a[i].scan();
    board[a[0].x][a[0].y]='r';
    board[a[1].x][a[1].y]='r';
    board[a[2].x][a[2].y]='k';
    for(i=-1;i<2;i++){
        for(j=-1;j<2;j++){
            if(Out(a[3].x+i,a[3].y+j))continue;
            if(!Check(a[3].x+i,a[3].y+j))break;
        }
        if(j<2)break;
    }
    if(i==2)puts("CHECKMATE");
    else puts("OTHER");
}