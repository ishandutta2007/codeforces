#include<bits/stdc++.h>
using namespace std;
char com[110];
int dpmn[101][51][2],dpmx[101][51][2];
int main(){
	int n,m,i,j;scanf("%s%d",com+1,&m);n=strlen(com+1);
//	cout<<"n="<<n<<"\n";
	for(i=1;i<=n;i++)for(j=0;j<=m;j++)
		dpmx[i][j][0]=dpmx[i][j][1]=-10000,dpmn[i][j][0]=dpmn[i][j][1]=10000;
	dpmx[1][com[1]=='T'][0]=dpmn[1][com[1]=='T'][0]=1;
	dpmx[1][com[1]=='F'][1]=dpmn[1][com[1]=='F'][1]=0;
	for(i=2;i<=n;i++)for(j=0;j<=m;j++)for(int k=0;k<=j;k++)
		if((com[i]=='T')^(k&1))
			dpmn[i][j][0]=min(dpmn[i][j][0],dpmn[i-1][j-k][1]),
			dpmn[i][j][1]=min(dpmn[i][j][1],dpmn[i-1][j-k][0]),
			dpmx[i][j][0]=max(dpmx[i][j][0],dpmx[i-1][j-k][1]),
			dpmx[i][j][1]=max(dpmx[i][j][1],dpmx[i-1][j-k][0]);
		else
			dpmn[i][j][0]=min(dpmn[i][j][0],dpmn[i-1][j-k][0]+1),
			dpmn[i][j][1]=min(dpmn[i][j][1],dpmn[i-1][j-k][1]-1),
			dpmx[i][j][0]=max(dpmx[i][j][0],dpmx[i-1][j-k][0]+1),
			dpmx[i][j][1]=max(dpmx[i][j][1],dpmx[i-1][j-k][1]-1);
//	for(i=1;i<=n;i++)for(j=0;j<=min(i,m);j++)printf(
//		"dpmn[%d][%d][0]=%d,dpmn[%d][%d][1]=%d,"
//		"dpmx[%d][%d][0]=%d,dpmx[%d][%d][1]=%d\n",
//		i,j,dpmn[i][j][0],i,j,dpmn[i][j][1],i,j,dpmx[i][j][0],i,j,dpmx[i][j][1]
//	);
	printf("%d",max(-dpmn[n][m][0],max(-dpmn[n][m][1],max(dpmx[n][m][0],dpmx[n][m][1]))));
	return 0;
}
/*1
FT
1
*/
/*2
FFFTFFF
2
*/
/*3
FTFTFTFFFFTFTFTTTTTTFFTTTTFFTFFFTFTFTFFTFTFTFFFTTTFTTFTTTTTFFFFTTT
12
*/