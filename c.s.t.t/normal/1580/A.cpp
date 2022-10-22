#include<bits/stdc++.h>
using namespace std;
int T,n,m,s[410][410],res;
char g[410][410];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m),res=0x3f3f3f3f;
		for(int i=1;i<=n;i++)scanf("%s",g[i]+1);
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+g[i][j]-'0';
		for(int l=1;l<=m;l++)for(int r=l+3;r<=m;r++){
			int mn=0x3f3f3f3f;
			for(int i=5;i<=n;i++){
				int j=i-5+1;
				int then=
					(r-l-1)-(s[j][r-1]-s[j][l]-s[j-1][r-1]+s[j-1][l])
				+(-j-1)-(-s[j][l]+s[j][l-1])
				+(-j-1)-(-s[j][r]+s[j][r-1])
				+(-s[j][r-1]+s[j][l]);
				mn=min(mn,then);
//				(i-j-1)-(s[i-1][l]-s[j][l]-s[i-1][l-1]+s[j][l-1]);
//				(i-j-1)-(s[i-1][r]-s[j][r]-s[i-1][r-1]+s[j][r-1]);
//				(s[i-1][r-1]-s[i-1][l]-s[j][r-1]+s[j][l]);
				int now=(r-l-1)-(s[i][r-1]-s[i][l]-s[i-1][r-1]+s[i-1][l])
				+(i)-(s[i-1][l]-s[i-1][l-1])
				+(i)-(s[i-1][r]-s[i-1][r-1])
				+(s[i-1][r-1]-s[i-1][l]);
				res=min(res,mn+now);
			}
		}
		printf("%d\n",res);
	}
	return 0;
}