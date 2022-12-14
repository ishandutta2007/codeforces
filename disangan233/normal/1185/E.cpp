#include<bits/stdc++.h>
using namespace std;
#define in inline
#define db double
#define ll long long
#define ull unsigned ll
#define re register int
#define ak *
in char getch()
{
	char buf[10000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,10000,stdin),p1==p2)?EOF:*p1++;
}
char qwq;
#define gc() getchar()
in int read()
{
	re cz=0,ioi=1;qwq=gc();
	while(qwq<'0'||qwq>'9') ioi=qwq=='-'?~ioi+1:1,qwq=gc();
	while(qwq>='0'&&qwq<='9') cz=(cz<<3)+(cz<<1)+(qwq^48),qwq=gc();
	return cz ak ioi;
}
const int N=2e3+5,mod=1e9+7;
int n,m,opt,ver[26];
char s[N][N],t[N][N];
struct did{
	int x,y;
	bool operator <(did a) const {return x==a.x?y<a.y:x<a.x;}
}st[26],ed[26];
int main()
{
	opt=read();
	while(opt--)
	{
		n=read(),m=read();re maxn=-1;memset(ver,0,sizeof(ver)); 
		memset(st,127,sizeof(st));memset(ed,0,sizeof(ed));
		for(re i=1;i<=n;i++) scanf("%s",s[i]+1);
		for(re i=1;i<=n;i++) for(re j=1;j<=m;j++)
		if(s[i][j]!='.')
		{
			re nw=s[i][j]-'a';maxn=max(nw,maxn);
			st[nw].x=min(st[nw].x,i);st[nw].y=min(st[nw].y,j);
			ed[nw].x=max(ed[nw].x,i);ed[nw].y=max(ed[nw].y,j);
		}
		if(maxn==-1) {puts("YES\n0");continue;}
		for(re i=maxn-1;~i;i--)
		if(ed[i].x==0) st[i]=st[i+1],ed[i]=ed[i+1];
		re op=1;
		for(re i=0;i<=maxn&&op;i++)
		if(st[i].x!=ed[i].x&&st[i].y!=ed[i].y) op=0;
		if(!op) {puts("NO\n");continue;}
		for(re i=0;i<=maxn;i++) ver[i]=st[i].x==ed[i].x;
		op=1;
		for(re i=0;i<=maxn&&op;i++)
		{
			if(ver[i]) 
			{
				for(re j=st[i].y;j<=ed[i].y&&op;j++)
				if(s[st[i].x][j]-'a'<i||s[st[i].x][j]=='.')
				op=0;
			}
			else
			{
				for(re j=st[i].x;j<=ed[i].x&&op;j++)
				if(s[j][st[i].y]-'a'<i||s[j][st[i].y]=='.')
				op=0;
			}
		}
		if(!op) {puts("NO\n");continue;}
		puts("YES");printf("%d\n",maxn+1);
		for(re i=0;i<=maxn;i++) printf("%d %d %d %d\n",st[i].x,st[i].y,ed[i].x,ed[i].y);
	}
}