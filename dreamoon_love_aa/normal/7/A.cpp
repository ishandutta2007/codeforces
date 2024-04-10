#include<stdio.h>
char Map[9][10];
int an;
main(){
    int i,j;
    for(i=0;i<8;i++)scanf("%s",Map[i]);
    for(i=0;i<8;i++){
        for(j=0;j<8;j++)
            if(Map[i][j]=='W')break;
        if(j==8)an++;
        for(j=0;j<8;j++)
            if(Map[j][i]=='W')break;
        if(j==8)an++;
    }
    if(an==16)puts("8");
    else printf("%d\n",an);
}