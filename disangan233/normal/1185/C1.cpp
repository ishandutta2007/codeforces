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
const int N=2e5+5;
int n,m,a[N],cnt[110],ans;
int main()
{
	n=read();m=read();
	for(re i=1;i<=n;i++) a[i]=read();
	for(re i=1,sum=0;i<=n;i++)
	{
		re ans=0,now=sum+a[i]-m;
		for(re j=100;now>0&&j;j--)
		{
			if(cnt[j]*j<=now) now-=cnt[j]*j,ans+=cnt[j];
			else ans+=(now-1)/j+1,now=0;
		}
		printf("%d ",ans);
		++cnt[a[i]],sum+=a[i];
	}
}