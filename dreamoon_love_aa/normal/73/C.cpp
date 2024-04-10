#include<stdio.h>
#define MAX 1000000000
char s[128];
int Map[26][26],dp[128][128][26];
int max(int x,int y){return x>y?x:y;}
main(){
    int n,x,i,j,k,l,K,an;
    char c[2][4];
    scanf("%s%d",s,&K);
    scanf("%d",&n);
    while(n--){
        scanf("%s%s%d",c[0],c[1],&x);
        Map[c[0][0]-'a'][c[1][0]-'a']=x;
    }
    for(i=0;s[i];i++)
        for(j=0;j<=i+1;j++)
            for(k=0;k<26;k++)dp[i][j][k]=-MAX;
    for(i=0;i<26;i++){
        if(i!=s[0]-'a')dp[0][1][i]=0;
        else dp[0][0][i]=0;
    }
    for(i=1;s[i];i++){
        for(j=0;j<=i&&j<=K;j++)
            for(k=0;k<26;k++)
                for(l=0;l<26;l++){
                    if(l==s[i]-'a')dp[i][j][l]=max(dp[i][j][l],dp[i-1][j][k]+Map[k][l]);
                    else dp[i][j+1][l]=max(dp[i][j+1][l],dp[i-1][j][k]+Map[k][l]);
                }
    }
    /*
    for(i=0;s[i];i++){
        for(j=0;j<=i+1;j++,puts(""))
            for(k=0;k<26;k++)printf("%d ",dp[i][j][k]);
        puts("-----------------");
    }
    */
    an=-MAX;
    for(j=0;j<=i&&j<=K;j++)
        for(k=0;k<26;k++)an=max(an,dp[i-1][j][k]);
    printf("%d\n",an);
}