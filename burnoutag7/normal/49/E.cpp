#include<bits/stdc++.h>
using namespace std;

int n,slen,tlen;
char s[55],t[55],a[55],b[55],c[55];
int f[55][55][26],g[55][55][26],dp[55][55];

int main(){

    scanf("%s",s+1);
    scanf("%s",t+1);
    scanf("%d",&n);
    slen=strlen(s+1);
    tlen=strlen(t+1);
    for(int i=1;i<=n;i++){
        static char buf[10];
        scanf("%s",buf);
        a[i]=*buf-'a';
        b[i]=buf[3]-'a';
        c[i]=buf[4]-'a';
    }
    for(int i=slen;i>=1;i--){
        f[i][i][s[i]-'a']=1;
        for(int j=i+1;j<=slen;j++){
            for(int k=i;k<j;k++){
                for(int e=1;e<=n;e++){
                    char &fa=a[e],&ls=b[e],&rs=c[e];
                    f[i][j][fa]|=f[i][k][ls]&&f[k+1][j][rs];
                }
            }
        }
    }
    for(int i=tlen;i>=1;i--){
        g[i][i][t[i]-'a']=1;
        for(int j=i+1;j<=tlen;j++){
            for(int k=i;k<j;k++){
                for(int e=1;e<=n;e++){
                    char &fa=a[e],&ls=b[e],&rs=c[e];
                    g[i][j][fa]|=g[i][k][ls]&&g[k+1][j][rs];
                }
            }
        }
    }
    memset(dp,0x3f,sizeof(dp));
    dp[0][0]=0;
    for(int i=1;i<=slen;i++){
        for(int j=1;j<=tlen;j++){
            for(int pi=0;pi<i;pi++){
                for(int pj=0;pj<j;pj++){
                    for(int ch=0;ch<26;ch++){
                        if(f[pi+1][i][ch]&&g[pj+1][j][ch])dp[i][j]=min(dp[i][j],dp[pi][pj]+1);
                    }
                }
            }
        }
    }
    printf("%d",dp[slen][tlen]==0x3f3f3f3f?-1:dp[slen][tlen]);

    return 0;
}