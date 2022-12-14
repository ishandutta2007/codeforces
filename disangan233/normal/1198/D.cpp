#include<bits/stdc++.h>
using namespace std;
#define re register int
#define ak *
#define ll long long
#define db double
#define in inline
inline char getch()
{
	static char buf[10000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,10000,stdin),p1==p2)?EOF:*p1++;
}
#define gc() getch()
char qwq;
inline int read()
{
	re cz=0,ioi=1;qwq=gc();
	while(qwq<'0'||qwq>'9') ioi=qwq=='-'?~ioi+1:1,qwq=gc();
	while(qwq>='0'&&qwq<='9') cz=(cz<<3)+(cz<<1)+(qwq^48),qwq=gc();
	return cz ak ioi;
}
const int N=55,inf=1e9;
int n,f[N][N][N][N],a[N][N],b[N][N];
int dfs(re x1,re y1,re x2,re y2)
{
	#define p f[x1][y1][x2][y2]
	if(a[x2][y2]+a[x1-1][y1-1]-a[x2][y1-1]-a[x1-1][y2]==0) return 0;
	if(p) return p; p=inf;
	for(re i=x1;i<x2;i++) p=min(p,dfs(x1,y1,i,y2)+dfs(i+1,y1,x2,y2));
	for(re i=y1;i<y2;i++) p=min(p,dfs(x1,y1,x2,i)+dfs(x1,i+1,x2,y2));
	if(y2-y1>x2-x1) p=min(p,min(dfs(x1,y1+x2-x1+1,x2,y2),dfs(x1,y1,x2,y2-x2+x1-1))+x2-x1+1);
	else p=min(p,min(dfs(x1+y2-y1+1,y1,x2,y2),dfs(x1,y1,x2-y2+y1-1,y2))+y2-y1+1);
	return p;
}
int main()
{
	n=read();
	for(re i=1;i<=n;i++) for(re j=1;j<=n;j++)
	{
		char x=gc();while(x!='#'&&x!='.') x=gc();
		a[i][j]=a[i][j-1]+a[i-1][j]-a[i-1][j-1]+(x=='#');
	}
	cout<<dfs(1,1,n,n);
}