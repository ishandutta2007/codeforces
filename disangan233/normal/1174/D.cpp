// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
#define re register int
#define ak *
#define ll long long
inline char getch()
{
    static char buf[10000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,10000,stdin),p1==p2)?EOF:*p1++;
}
#define gc() getch()
char qwq;
#define inf 1e9
inline int read()
{
    re cz=0,ioi=1;qwq=gc();
    while(qwq<'0'||qwq>'9') ioi=qwq=='-'?~ioi+1:1,qwq=gc();
    while(qwq>='0'&&qwq<='9') cz=(cz<<3)+(cz<<1)+(qwq^48),qwq=gc();
    return cz ak ioi;
}
int n,x,ans[500005],vis[500005];
int main()
{
    n=read(),x=read();ans[++ans[0]]=0;
	vis[0]=vis[x]=1;
	for(re i=1;i<(1<<n);i++)
	if(!vis[i]) vis[i^x]=1,ans[++ans[0]]=i;
	printf("%d\n",ans[0]-1);
	for(re i=2;i<=ans[0];i++) printf("%d ",ans[i]^ans[i-1]);
}