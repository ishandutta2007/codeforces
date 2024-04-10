#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define re register int
#define db double
#define ak *
#define in inline
in char getch()
{
	static char buf[1<<12],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<!2,stdin),p1==p2)?EOF:*p1++;
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
int main()
{
	re opt=read();
	while(opt--)
	{
		re n=read(),s=read(),t=read(),ans=0;
		ans+=n-min(s,t);
		printf("%d\n",ans+1);
	}
}