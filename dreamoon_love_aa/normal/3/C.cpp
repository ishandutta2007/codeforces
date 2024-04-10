#include<stdio.h>
char s[4][8];
int O,X,used[3][3];
bool Win(char c){
    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++)
            if(s[i][j]!=c)break;
        if(j==3)return 1;
    }
    for(i=0;i<3;i++){
        for(j=0;j<3;j++)
            if(s[j][i]!=c)break;
        if(j==3)return 1;
    }
    for(i=0;i<3;i++)
        if(s[i][i]!=c)break;
    if(i==3)return 1;
    for(i=0;i<3;i++)
        if(s[i][2-i]!=c)break;
    return i==3;
}
bool XWin(){return Win('X');}
bool OWin(){return Win('0');}
bool Valid(){
    int i,j,k,count=0;
    if(X-O>1)return 0;
    if(O>X)return 0;
    if(XWin()&&X==O)return 0;
    if(OWin()&&X==O+1)return 0;
    for(i=0;i<3;i++){
        if(s[i][0]!='.'){
            for(j=1;j<3;j++)
                if(s[i][j]!=s[i][j-1])break;
            if(j==3){
                for(k=0;k<3;k++)
                    if(used[i][k]==0){
                        used[i][k]=1;
                        count++;
                    }
            }
        }
    }
    for(i=0;i<3;i++){
        if(s[0][i]!='.'){
            for(j=1;j<3;j++)
                if(s[j][i]!=s[j-1][i])break;
            if(j==3){
                for(k=0;k<3;k++)
                    if(used[k][i]==0){
                        used[k][i]=1;
                        count++;
                    }
            }
        }
    }
    if(count>5)return 0;
    return 1;
}
main(){
    int i,j;
    for(i=0;i<3;i++)scanf("%s",s[i]);
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(s[i][j]=='0')O++;
            else if(s[i][j]=='X')X++;
        }
    }
    if(!Valid())puts("illegal");
    else if(XWin())puts("the first player won");
    else if(OWin())puts("the second player won");
    else if(O+X==9)puts("draw");
    else if(O==X)puts("first");
    else puts("second");
}