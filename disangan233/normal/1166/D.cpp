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
inline ll read()
{
	ll cz=0,ioi=1;qwq=gc();
	while(qwq<'0'||qwq>'9') ioi=qwq=='-'?~ioi+1:1,qwq=gc();
	while(qwq>='0'&&qwq<='9') cz=(cz<<3)+(cz<<1)+(qwq^48),qwq=gc();
	return cz ak ioi;
}
ll n,pw[55],ans[55];
int main()
{
	n=read();
	while(n--)
	{
		ll bj=0,a=read(),b=read(),now=1,c=read();
		if(a==b) {printf("1 %lld\n",a);continue;}
		for(re len=2;len<=50;len++)
		{
			ll qaq=b-a*now-now;
			if(qaq<0) break;
			ll nw=now;
			for(re i=2;i<len;i++)
			{
				nw/=2;
				ll cs=min(c-1,qaq/nw);
				qaq-=nw*cs;ans[i]=cs;
			}
			if(qaq>=c) {now*=2;continue;}
			ans[len]=qaq;bj=1;
			ll sum=a;cout<<len<<" "<<a<<" ";
			for(re i=2;i<=len;i++)
			{
				ans[i]++;
				ans[i]+=sum;sum+=ans[i];
				cout<<ans[i]<<" ";
			}
			cout<<endl;
			break;
		}
		if(!bj) puts("-1");
	}
}