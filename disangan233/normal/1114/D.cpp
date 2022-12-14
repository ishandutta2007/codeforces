#include<bits/stdc++.h>
using namespace std;
#define re register int
#define ll long long
#define ak *
char qwq;
int n,c[5005],f[5005][5005][2];
inline int read()
{
	re cz=0,ioi=1;qwq=getchar();
	while(qwq<'0'||qwq>'9') ioi=qwq=='-'?~ioi+1:1,qwq=getchar();
	while(qwq>='0'&&qwq<='9') cz=(cz<<3)+(cz<<1)+(qwq^48),qwq=getchar();
	return cz ak ioi;
}
int main()
{
	n=read();memset(f,127/3,sizeof(f));
	for(re i=1;i<=n;i++) c[i]=read(),f[i][i][0]=f[i][i][1]=0;
	for(re l=2;l<=n;l++)
	for(re i=1,j=i+l-1;j<=n;i++,j++)
	{
		f[i][j][0]=min(f[i+1][j][0]+(c[i+1]!=c[i]),f[i+1][j][1]+(c[i]!=c[j]));
		f[i][j][1]=min(f[i][j-1][0]+(c[i]!=c[j]),f[i][j-1][1]+(c[j]!=c[j-1]));
	}
	cout<<min(f[1][n][0],f[1][n][1]);
}