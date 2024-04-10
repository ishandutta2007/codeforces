#include<bits/stdc++.h>
using namespace std;
const int M=1e9+7;
int n,m;
char s[205],c[205];
int nxt[205][2];
int f[205][205][205][2];
int main(){
	scanf("%d%s",&n,s+1),m=strlen(s+1);
	for(int i=0;i<=m;i++){
		for(int j=1;j<=i;j++)c[j]=s[j];
		for(int j=0;j<2;j++){
			c[i+1]=j+'(';
			for(int k=1;k<=i+1;k++){
				bool ok=1;
				for(int l=1,r=i+2-k;l<=k&&ok;l++,r++)ok&=(s[l]==c[r]);
				if(ok)nxt[i][j]=k;
			}
		}
	}
	f[0][0][0][0]=1;
	for(int i=0;i<n+n;i++)for(int j=0;j<=i;j++)
		for(int k=0;k<=m;k++)for(int l=0;l<2;l++)if(f[i][j][k][l]){
			if(j>0)(f[i+1][j-1][nxt[k][1]][l|(nxt[k][1]==m)]+=f[i][j][k][l])%=M;
			(f[i+1][j+1][nxt[k][0]][l|(nxt[k][0]==m)]+=f[i][j][k][l])%=M;
		}
	int ans=0;
	for(int i=0;i<=m;i++)(ans+=f[n+n][0][i][1])%=M;
	printf("%d",ans);
}