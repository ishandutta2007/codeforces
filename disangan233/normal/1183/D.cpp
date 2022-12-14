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
#define gc() getchar()
char qwq;
inline int read()
{
	re cz=0,ioi=1;qwq=gc();
	while(qwq<'0'||qwq>'9') ioi=qwq=='-'?~ioi+1:1,qwq=gc();
	while(qwq>='0'&&qwq<='9') cz=(cz<<3)+(cz<<1)+(qwq^48),qwq=gc();
	return cz ak ioi;
}
int n,a[200005];
priority_queue<int>q;
int main()
{
	re t=read();
	while(t--)
	{
		while(!q.empty()) q.pop();
		n=read();for(re i=1;i<=n;i++) a[i]=read();
		sort(a+1,a+n+1);
		for(re i=1,j=1;i<=n;i=j)
		{
			j=i;
			while(a[j]==a[i]&&j<=n) j++;
			q.push(j-i);
		}
		re minn=1e9,ans=0;
		while(!q.empty()&&minn)
		{
			if(minn>q.top()) ans+=q.top(),minn=q.top()-1;
			else minn=min(minn,q.top()),ans+=minn,minn--;
			q.pop();
		}
		printf("%d\n",ans);
	}
}