#include<cmath>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define pb push_back
using namespace std;
const int N=510;
int n,m,dp[N][N][N],nex[N],tr[N][2];char s[N],t[N];
void cmin(int &x,int y){y<x?x=y:0;}
int main(){
    scanf("%d%d%s%s",&n,&m,s+1,t+1);
    memset(dp,0x3f,sizeof(dp));
	for (int i=2,j=0;i<=m;i++)
	{
		while (j && t[j+1]!=t[i]) j=nex[j];
		if (t[j+1]==t[i]) j++;
		nex[i]=j;
	}
    // for(int i=1;i<=m;i++)printf("%d ",nex[i]);puts("");
    for(int i=0;i<=m;i++){
        for(int j=0;j<2;j++){
            int k=i;
            while(k&&t[k+1]!=j+'0')k=nex[k];
            if(t[k+1]==j+'0')k++;
            tr[i][j]=k;
        }
    }
    // for(int i=0;i<=m;i++)printf("%d %d\n",tr[i][0],tr[i][1]);
    dp[0][0][0]=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<=m;j++)
            for(int k=0;k<=n-m+1;k++){
                int to=tr[j][s[i+1]-'0'];
                cmin(dp[i+1][to][k+(to==m)],dp[i][j][k]);
                to=tr[j][(s[i+1]-'0')^1];
                cmin(dp[i+1][to][k+(to==m)],dp[i][j][k]+1);
            }
    for(int i=0;i<=n-m+1;i++){
        int ans=1e9;
        for(int j=0;j<=m;j++)cmin(ans,dp[n][j][i]);
        printf("%d ",ans<=n?ans:-1);
    }
    return 0;
}