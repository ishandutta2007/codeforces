#include<bits/stdc++.h>
using namespace std;
int n,m,a[255],pre[255];
int f[255][255][255];
int s[255];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),pre[i]=pre[i-1]+a[i];
	memset(f,0x3f,sizeof(f));
	f[0][m][0]=0;
	for(int i=1;i<=n;i++){
		memset(s,0x3f,sizeof(s));
		for(int j=m;j>=0;j--){
			for(int k=0;k<=m;k++)
				s[k]=min(s[k],f[i-1][j][k]);
			for(int k=j;k<=m;k++)
				f[i][j][k]=min(f[i][j][k],s[k-j]+abs(k-pre[i]));
		}
	}
	int mn=1e9;
	for(int i=0;i<=m;i++)mn=min(mn,f[n][i][m]);
	printf("%d",mn);
}