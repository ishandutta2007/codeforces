#include<stdio.h>
int d[6][8]={
    {3,3,0,4,4,0,3,3},
    {3,3,0,4,4,0,3,3},
    {2,2,0,3,3,0,2,2},
    {2,2,0,3,3,0,2,2},
    {1,1,0,2,2,0,1,1},
    {1,1,0,2,2,0,1,1}
};
char s[6][12];
int main(){
    for(int i=0;i<6;i++)scanf("%s",s[i]);
    int x=1,y=1,ma=0;
    for(int i=0;i<6;i++){
        for(int j=0;j<8;j++){
            if(s[i][j]=='.'){
                if(d[i][j]>ma){
                    ma=d[i][j];
                    x=i;
                    y=j;
                }
            }
        }
    }
    s[x][y]='P';
    for(int i=0;i<6;i++)puts(s[i]);
    return 0;
}