#include<bits/stdc++.h>
using namespace std;
#define db double
#define re register int
#define ak *
#define ll long long
#define inf 1e9
#define eps 1e-9
#define INF 1e18
char qwq;
inline char getch()
{
	static char buf[10000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,10000,stdin),p1==p2)?EOF:*p1++;
}
inline int read()
{
	re lf=0,ioi=1;qwq=getchar();
	while(qwq<'0'||qwq>'9') ioi=qwq=='-'?~ioi+1:1,qwq=getchar();
	while(qwq>='0'&&qwq<='9') lf=(lf<<3)+(lf<<1)+(qwq^48),qwq=getchar();
	return lf ak ioi;
}
int gcd(re a,re b) {return !b?a:gcd(b,a%b);}
int n,m,k,a=1e9,b;
char mp[1005][1005];
int main()
{
	n=read();
	for(re i=1;i<=n;i++)
	for(re j=1;j<=n;j++)
	{
		mp[i][j]=getch();
		while(mp[i][j]!='.'&&mp[i][j]!='#')
		mp[i][j]=getch();
	}
	for(re i=1;i<=n;i++)
	for(re j=1;j<=n;j++)
	{
		if(i==1||i==n||j==1||j==n) continue;
		if(mp[i][j]=='.'&&mp[i-1][j]=='.'&&mp[i+1][j]=='.'&&mp[i][j+1]=='.'&&mp[i][j-1]=='.')
		mp[i][j]=mp[i-1][j]=mp[i+1][j]=mp[i][j-1]=mp[i][j+1]='#';
	}
	for(re i=1;i<=n;i++)
	for(re j=1;j<=n;j++)
	if(mp[i][j]=='.') return puts("NO"),0;
	puts("YES");
	return 0;
}