#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=205;

char as[maxn],bs[maxn];
int a[maxn],b[maxn];
int n,m;
int dp[maxn][maxn][maxn];
int nxt[maxn][maxn][maxn];
char opt[maxn<<1];

int main(){
    cin>>(as+1)>>(bs+1);n=strlen(as+1);m=strlen(bs+1);
    for(int i=1;i<=n;i++){a[i]=as[i]=='('?1:-1;}
    for(int i=1;i<=m;i++){b[i]=bs[i]=='('?1:-1;}
    memset(dp,0x3f,sizeof(dp));dp[0][0][0]=0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            for(int k=0;k<=max(n,m);k++){
                if(i==0&&j==0&&k==0)continue;
                if(i&&j&&a[i]==b[j]&&k-a[i]>=0){if(dp[i-1][j-1][k-a[i]]+1<dp[i][j][k]){dp[i][j][k]=dp[i-1][j-1][k-a[i]]+1;nxt[i][j][k]=1;}}
                if(i&&k-a[i]>=0){if(dp[i-1][j][k-a[i]]+1<dp[i][j][k]){dp[i][j][k]=dp[i-1][j][k-a[i]]+1;nxt[i][j][k]=2;}}
                if(j&&k-b[j]>=0){if(dp[i][j-1][k-b[j]]+1<dp[i][j][k]){dp[i][j][k]=dp[i][j-1][k-b[j]]+1;nxt[i][j][k]=3;}}
            }
            for(int k=1;k<=max(n,m);k++){
                if(dp[i][j][k-1]+1<dp[i][j][k]){dp[i][j][k]=dp[i][j][k-1]+1;nxt[i][j][k]=4;}
            }
            for(int k=max(n,m)-1;k>=0;k--){
                if(dp[i][j][k+1]+1<dp[i][j][k]){dp[i][j][k]=dp[i][j][k+1]+1;nxt[i][j][k]=5;}
            }
        }
    }
    int ci=n,cj=m,ck=0;
    for(int i=dp[n][m][0];i>=1;i--){
        if(nxt[ci][cj][ck]==1){
            opt[i]=(a[ci]==-1?')':'(');ck-=a[ci];ci--;cj--;
        }else if(nxt[ci][cj][ck]==2){
            opt[i]=(a[ci]==-1?')':'(');ck-=a[ci];ci--;
        }else if(nxt[ci][cj][ck]==3){
            opt[i]=(b[cj]==-1?')':'(');ck-=b[cj];cj--;
        }else if(nxt[ci][cj][ck]==4){
            opt[i]='(';ck--;
        }else if(nxt[ci][cj][ck]==5){
            opt[i]=')';ck++;
        }
    }
    cout<<(opt+1);
    return 0;
}