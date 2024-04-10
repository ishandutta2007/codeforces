#include<stdio.h>
bool S(char c){return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';}
main(){
    char s[3][256];
    int i,j,k;
    for(i=0;i<3;i++)gets(s[i]);
    for(i=0;i<3;i++){
        k=0;
        for(j=0;s[i][j];j++)
            if(S(s[i][j]))k++;
        if(i==1){
            if(k!=7)break;
        }
        else{
            if(k!=5)break;
        }
    }
    if(i==3)puts("YES");
    else puts("NO");
}