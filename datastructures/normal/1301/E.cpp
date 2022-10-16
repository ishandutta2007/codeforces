#include <iostream>
#include <cstdio>
using namespace std;
int n,m,f[505][505][255];
int q,r1,c1,r2,c2;
char a[505][505];
inline int read(){
	register int x=0;
	register char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
inline void out(register int x,register int fg=1){
	if (x==0){
		if (fg==1)puts("0");
		return;
	}
	out(x/10,0);
	putchar(x%10+'0');
	if (fg==1)puts("");
	return;
}
int main(){
	cin>>n>>m>>q;
	for (register int i=1;i<=n;i++)scanf("%s",a[i]+1);
	for (register int i=1;i<=n;i++)
		for (register int j=1;j<=m;j++)
			f[i][j][1]=1;
	for (register int k=2;k<=min(n/2,m/2);k++)
		for (register int i=1;i<=n;i++)
			for (register int j=1;j<=m;j++){
				if (i+k-1>n||j+k-1>m)continue;
				f[i][j][k]=(a[i][j]==a[i+1][j]&&a[i][j]==a[i][j+1]&&a[i][j]==a[i+1][j+1]&&f[i][j][k-1]&&f[i+1][j][k-1]&&f[i][j+1][k-1]&&f[i+1][j+1][k-1]);
			}
	for (register int k=1;k<=min(n/2,m/2);k++)
		for (register int i=1;i<=n;i++)
			for (register int j=1;j<=m;j++){
				int now=f[i][j][k];
				f[i][j][k]=0;
				if (i+2*k-1>n||j+2*k-1>m)continue;
				if (a[i][j]=='R'&&a[i+k][j]=='Y'&&a[i][j+k]=='G'&&a[i+k][j+k]=='B')f[i][j][k]=(now&&f[i+k][j][k]&&f[i][j+k][k]&&f[i+k][j+k][k]);
				else f[i][j][k]=0;
				f[i][j][k]=f[i][j][k]+f[i-1][j][k]+f[i][j-1][k]-f[i-1][j-1][k];
			}
	while(q--){
		r1=read(),c1=read(),r2=read(),c2=read();
		int ans=0;
		for (register int i=1;i<=min((r2-r1+1),(c2-c1+1))/2;i++)
			if (f[r2-2*i+1][c2-2*i+1][i]-f[r2-2*i+1][c1-1][i]-f[r1-1][c2-2*i+1][i]+f[r1-1][c1-1][i]>0)ans=4*i*i;
			else break;
		out(ans);
	} 
	return 0;
}