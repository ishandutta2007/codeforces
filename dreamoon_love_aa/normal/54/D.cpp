#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int dp[256][128],n,kmp[128],next[128][26],back[256][128];
void Pre(char s[]){
    int i,key=1;
    kmp[0]=-1;
    for(i=2;i<=n;i++){
        while(key>0&&s[i]!=s[key]){
            key=kmp[key-1]+1;
        }
        kmp[i]=key++;
    }
    for(i=0;i<=n;i++){
        key=i;
        if(key==n)key=kmp[key];
        while(key){
            next[i][s[key+1]-'a']=max(next[i][s[key+1]-'a'],key+1);
            key=kmp[key];
        }
        next[i][s[1]-'a']=max(next[i][s[1]-'a'],1);
    }
}
void error(){puts("No solution");}
void print(int x,int y){
    if(x==0)return;
    print(x-1,dp[x][y]);
    putchar(back[x][y]+'a');
}
main(){
    char s[128],boo[128];
    int N,K,i,j,k;
    scanf("%d%d",&N,&K);
    scanf("%s%s",s+1,boo);
    n=strlen(s+1);
    Pre(s);
    memset(dp,-1,sizeof(dp));
    dp[0][0]=0;
    for(i=0;i<N;i++){
        for(j=0;j<=i&&j<=n;j++){
            if(dp[i][j]<0)continue;
            if(i>=n){
                if(boo[i-n]=='0'){
                    if(j==n)continue;
                }
                else{
                    if(j!=n)continue;
                }
            }
            for(k=0;k<K;k++){
                dp[i+1][next[j][k]]=j;
                back[i+1][next[j][k]]=k;
            }
        }
    }
    if(boo[N-n]=='1'){
        if(dp[N][n]>=0)print(N,n),puts("");
        else error();
    }
    else{
        for(i=0;i<n;i++)
            if(dp[N][i]>=0){
                print(N,i);
                puts("");
                break;
            }
        if(i==n)error();
    }
}