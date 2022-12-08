#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[1010],d[1010][1010],e[1010][1010];
int main(){
	int n,m;scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	sort(a,a+n);
	int ans=0;
	for(int j=0;j<n;j++)e[1][j]=j;
	int X=1;
	while(X*(m-1)<=100000)X++;
	for(int t=1;t<X;t++){
		for(int i=2;i<=m;i++){
			for(int j=0,k=0;j<n;j++){
				while(a[j]-a[k]>=t)k++;
				d[i][j]=e[i-1][k];
				e[i][j+1]=e[i][j]+d[i][j];
				if(e[i][j+1]>=mod)e[i][j+1]-=mod;
			}
		}
		ans+=e[m][n];
		if(ans>=mod)ans-=mod;
	}
	printf("%d\n",ans);
}