#include<bits/stdc++.h>
using namespace std;
#define re register int
#define ll long long
#define ak *
#define in inline
#define db double
in char getch()
{
	static char buf[1<<12],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<12,stdin),p1==p2)?EOF:*p1++;
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
const int N=45;
int n,k,g[N][N],ans,cnt[N],ch[N];
bool dfs(re u,re nw)
{
	ch[nw]=u;
	if(nw>ans) return ans=nw,true;
	for(re i,v=u+1;v<=n;v++)
	{
		if(!g[u][v]||nw+cnt[v]<=ans) continue;
		for(i=1;i<=nw;i++)
		if(!g[ch[i]][v]) break;
		if(i>nw&&dfs(v,nw+1)) return true; 
	}
	return false;
}
in int bron_kerbosch()
{
	for(re i=n;i;i--) dfs(i,1),cnt[i]=ans;
	return ans;
}
int main()
{
	n=read();k=read();
	for(re i=1;i<=n;i++) 
	for(re j=1;j<=n;j++)
	g[i][j]=read();
	re cnt=bron_kerbosch();
	if(!cnt) return puts("0"),0;
	db per=1.0*k/cnt,tot=cnt*(cnt-1)/2.0;
	printf("%.8lf",tot*pow(per,2));
	return 0;
}