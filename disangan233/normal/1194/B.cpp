#include<bits/stdc++.h>
using namespace std;
#define re register int
#define ll long long
#define db double
#define ak *
#define in inline
in char getch()
{
	static char buf[10000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,10000,stdin),p1==p2)?EOF:*p1++;
}
char qwq;
#define gc() getch()
in int read()
{
	re cz=0,ioi=1;qwq=gc();
	while(qwq<'0'||qwq>'9') ioi=qwq=='-'?~ioi+1:1,qwq=gc();
	while(qwq>='0'&&qwq<='9') cz=(cz<<3)+(cz<<1)+(qwq^48),qwq=gc();
	return cz ak ioi;
}
const int N=5e5+5,M=1e6+5;
int n,m,tot,x[N],y[N];
char a[N];
int main()
{
	re t=read();
	while(t--)
	{
		re n=read(),m=read();
		fill(x+1,x+n+1,0);fill(y+1,y+m+1,0);
		for(re i=1;i<=n;i++)
		for(re j=1;j<=m;j++)
		{
			re k=(i-1)*m+j;
			a[k]=getch();
			while(a[k]!='.'&&a[k]!='*') a[k]=getch();
			x[i]+=a[k]=='*';y[j]+=a[k]=='*';
		}
		re ans=0;
		for(re i=1;i<=n;i++)
		for(re j=1;j<=m;j++)
		ans=max(ans,x[i]+y[j]+(a[(i-1)*m+j]=='.'));
		printf("%d\n",n+m-ans);
	}
}