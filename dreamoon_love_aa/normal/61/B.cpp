#include<stdio.h>
#include<string.h>
char S[3][999],s[6][999];
int N;
bool alpha(char c){return (c>='A'&&c<='Z')||(c>='a'&&c<='z');}
main(){
    int i,j,k,n;
    char input[999];
    for(i=0;i<3;i++){
        scanf("%s",S[i]);
        for(j=k=0;S[i][j];j++)
            if(alpha(S[i][j])){
                S[i][k++]=S[i][j];
                if(S[i][k-1]>='a'&&S[i][k-1]<='z')S[i][k-1]+='A'-'a';
            }
        S[i][k]=0;
    }
    strcpy(s[0],S[0]);strcat(s[0],S[1]);strcat(s[0],S[2]);
    strcpy(s[1],S[0]);strcat(s[1],S[2]);strcat(s[1],S[1]);
    strcpy(s[2],S[1]);strcat(s[2],S[0]);strcat(s[2],S[2]);
    strcpy(s[3],S[1]);strcat(s[3],S[2]);strcat(s[3],S[0]);
    strcpy(s[4],S[2]);strcat(s[4],S[0]);strcat(s[4],S[1]);
    strcpy(s[5],S[2]);strcat(s[5],S[1]);strcat(s[5],S[0]);
    scanf("%d",&n);
    while(n--){
        scanf("%s",input);
        for(i=j=0;input[i];i++){
            if(alpha(input[i])){
                if(input[i]>='a'&&input[i]<='z')input[i]+='A'-'a';
                input[j++]=input[i];
            }
        }
        input[j]=0;
        for(i=0;i<6;i++)
            if(!strcmp(input,s[i]))break;
        if(i==6)puts("WA");
        else puts("ACC");
    }
}