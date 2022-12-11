#include<bits/stdc++.h>
using namespace std;
const int N=200,M=1e6+50;
int n,d[N][N],m,b[M],num;bool flag[M];
int main(){
	scanf("%d",&n);
	memset(d,0x3f,sizeof(d));
	for(int i=1;i<=n;i++)d[i][i]=0;
	for(int i=1;i<=n;i++)for(int j=1,x;j<=n;j++){
		scanf("%1d",&x);if(x)d[i][j]=1;
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	scanf("%d",&m);
	for(int i=1,x;i<=m;i++)scanf("%d",&b[i]);
	for(int i=2,j=1;i<m;i++){
		if(d[b[j]][b[i+1]]>i-j)flag[i]=1,num++;
		else j=i;
	}
	printf("%d\n",m-num);
	for(int i=1;i<=m;i++)if(!flag[i])printf("%d ",b[i]);
	return 0;
}