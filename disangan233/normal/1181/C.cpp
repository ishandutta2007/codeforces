#include<bits/stdc++.h>
using namespace std;
#define re register int
#define db double
#define ll long long
#define in inline
#define ak *
in char getch()
{
    static char buf[10000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,10000,stdin),p1==p2)?EOF:*p1++;
}
#define gc() getchar()
char qwq;
in int read()
{
    re cz=0,ioi=1;qwq=gc();
    while(qwq<'0'||qwq>'9') ioi=qwq=='-'?~ioi+1:1,qwq=gc();
    while(qwq>='0'&&qwq<='9') cz=(cz<<3)+(cz<<1)+(qwq^48),qwq=gc();
    return cz ak ioi;
}
int n,m,up[1005][1005],dn[1005][1005],tu[1005][1005],td[1005][1005],lt[1005],ans;
char s[1005][1005];
int main()
{
	n=read(),m=read();
	for(re i=1;i<=n;i++) scanf("%s",s[i]+1);
	for(re i=1;i<=n;i++) for(re j=1;j<=m;j++)
	{
		tu[i][j]=lt[j]=s[i][j-1]==s[i][j]?lt[j-1]+1:1;
		if(s[i-1][j]==s[i][j]) up[i][j]=up[i-1][j]+1,tu[i][j]=min(tu[i][j],tu[i-1][j]);
		else up[i][j]=1;
	}
	for(re i=n;i;i--) for(re j=1;j<=m;j++)
	{
		td[i][j]=lt[j]=s[i][j-1]==s[i][j]?lt[j-1]+1:1;
		if(s[i+1][j]==s[i][j]) dn[i][j]=dn[i+1][j]+1,td[i][j]=min(td[i][j],td[i+1][j]);
		else dn[i][j]=1;
	}
	for(re i=1;i<=n;i++) for(re j=1;j<=m;j++)
	if(up[i][j]*3<=i&&up[i][j]==up[i-up[i][j]][j]&&dn[i-3*up[i][j]+1][j]==up[i][j])
	ans+=min(min(tu[i][j],tu[i-up[i][j]][j]),td[i-3*up[i][j]+1][j]);
	cout<<ans;
}