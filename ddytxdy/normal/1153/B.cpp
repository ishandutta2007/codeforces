#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=110;
int n,m,h,maxn[2][N],a[N][N],x;
int main(){
	scanf("%d%d%d",&n,&m,&h);
	for(int i=1;i<=m;i++)scanf("%d",&maxn[0][i]);
	for(int i=1;i<=n;i++)scanf("%d",&maxn[1][i]);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
		scanf("%d",&x);
		if(x)a[i][j]=min(maxn[0][j],maxn[1][i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)printf("%d ",a[i][j]);
		puts("");
	}
	return 0;
}