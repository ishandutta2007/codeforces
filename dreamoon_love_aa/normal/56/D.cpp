#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define SIZE 1024
#define DELETE 0
#define INSERT 1
#define REPLACE 2
#define SAME 3
int dp[SIZE][SIZE],back[SIZE][SIZE];
char s1[1024],s2[1024];
void track(int x,int y){
    if(x+y==0)return;
    if(back[x][y]==SAME||back[x][y]==REPLACE){
        track(x-1,y-1);
        if(back[x][y]!=SAME)printf("REPLACE %d %c\n",y,s2[y]);
    }
    else if(back[x][y]==INSERT){
        track(x,y-1);
        printf("INSERT %d %c\n",y,s2[y]);
    }
    else{
        track(x-1,y);
        printf("DELETE %d\n",y+1);
    }
}
main(){
    int l1,l2,i,j;
    gets(s1+1);
    gets(s2+1);
    l1=strlen(s1+1);
    l2=strlen(s2+1);
    for(i=1;i<=l1;i++){
        dp[i][0]=i;
        back[i][0]=DELETE;
    }
    for(i=1;i<=l2;i++){
        dp[0][i]=i;
        back[0][i]=INSERT;
    }
    for(i=1;i<=l1;i++){
        for(j=1;j<=l2;j++){
            if(s1[i]==s2[j]){
                dp[i][j]=dp[i-1][j-1];
                back[i][j]=SAME;
            }
            else{
                dp[i][j]=dp[i-1][j-1]+1;
                back[i][j]=REPLACE;
            }
            if(dp[i-1][j]+1<dp[i][j]){
                dp[i][j]=dp[i-1][j]+1;
                back[i][j]=DELETE;
            }
            if(dp[i][j-1]+1<dp[i][j]){
                dp[i][j]=dp[i][j-1]+1;
                back[i][j]=INSERT;
            }
        }
    }
    printf("%d\n",dp[l1][l2]);
    track(l1,l2);
}